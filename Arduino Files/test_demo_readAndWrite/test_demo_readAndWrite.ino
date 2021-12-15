#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <SPI.h>

char ssid[] = "RowanWiFi"; // replace MySSID with your WiFi network name
char pass[] = ""; //replace MyPASS with your WiFi network password
unsigned long myChannelNumber = 1563202; // replace 0000000 with your channel number
const char * myWriteAPIKey = "H1R0O90R97HW8O8V"; // replace MyAPIKEY with your thingspeak write API key
const char * myReadAPIKey = "YB59CV1CV30WXQSN";
const int FieldNumber2 = 2;

// Create WiFi client and ThingSpeak class.
WiFiClient client;
ThingSpeakClass ts;

// WiFi initialization
void init_WIFI()
{
  // Serial print commands for testing. 
  // If you are using an FTDI and aren't in programming mode, you'll be able to see these.
  Serial.print("Attempting to connect to SSID: ");
  Serial.println(ssid);

  // While not connected, attempt to connect
  while (WiFi.status() != WL_CONNECTED) 
  {
    // Connect to the network
    WiFi.begin(ssid, pass);
    // Delay 5 seconds
    delay(5000);
    
    Serial.print(".");
  }
  
  Serial.println("\nConnected.");
}

// Initial board set-up
void setup() 
{
  // Initialize UART to 115200 baud rate
  Serial.begin(115200);

  // Set WiFi mode
  WiFi.mode(WIFI_STA);

  // Initialize ThingSpeak client
  ts.begin(client);
}

// Loop runs constantly
void loop() 
{
  //If not connected, connect to wifi
  if (WiFi.status() != WL_CONNECTED) 
  {
    init_WIFI();
  }
  
  int newByte = 0; // incoming byte from serial input
  char c; //Variable to hold incoming character
  String output = ""; //Variable to hold the concatanated string

  // Wait until there is any data available on the serial buffer
  while (Serial.available() == 0)
  {
    delay(100);
  }
  
  // Boolean to track if the message is finished
  bool receivedEOM = false;

  // Until an end-of-message character is received...
  while (!receivedEOM)
  {
    // If there is data in the serial buffer...
    if (Serial.available() > 0)
    {
      // Read in the new data and convert to a character
      newByte = Serial.read();
      c = (char) newByte;

      // If a semi-colon (end-of-message character) is received, end the message
      if (c == ';')
      {
        receivedEOM = true;
      }
      // Otherwise, add it to the message
      else
      {
        output += c; //add it to the string
      }
    }
  }

  // Set a ThingSpeak field. If you have multiple sensors, you'll use multiple fields.
  ts.setField(1, output);

  // Upload the data to ThingSpeak. Receive an integer code back from the site.
  int code = ts.writeFields(myChannelNumber, myWriteAPIKey);

  // Code 200 indicates a successful upload. Other codes indicate errors.
  if (code == 200) 
  {
    Serial.println("Channel update successful.");
  }
  else 
  {
    Serial.println("Problem setting Field 1. HTTP error code " +
    String(code));
  }
  
  // Wait 15.5 seconds to update the channel again since ThingSpeak is rate limited.
  // You can only upload data every 15 seconds.
  delay(15500);
}

void readSensor2(void)
{
 //------------------- Read Channel 2 ----------------//

  long temp = ts.readLongField(myChannelNumber, FieldNumber2, myReadAPIKey);
  int statusCode = ts.getLastReadStatus();
  if (statusCode == 500)
  {
    Serial.print("Temperature: ");
    Serial.println(temp);
  }
  else
  {
    Serial.println("Unable to read channel / No internet connection");
  }
  delay(100);
  //----------------------------------------------//
}
