#include <ESP8266WiFi.h>
//#include "secrets.h"
#include "ThingSpeak.h" // always include thingspeak header file after other header files and custom macros

char ssid[] = "RowanWiFi";   // your network SSID (name) 
char pass[] = "";   // your network password
WiFiClient  client;

// Counting channel details
unsigned long counterChannelNumber = 1563202;
const char * myCounterReadAPIKey = "YB59CV1CV30WXQSN";
unsigned int counterFieldNumber = 1; 

void setup() {
 Serial.begin(115200);  // Initialize serial
 while (!Serial) {
   ; // wait for serial port to connect. Needed for native USB port only
 }
 
 WiFi.mode(WIFI_STA); 
 ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop() {

//  int statusCode = 0;
 
 // Connect or reconnect to WiFi
 if(WiFi.status() != WL_CONNECTED){
   Serial.print("Attempting to connect to SSID: ");
   Serial.println(ssid);
   while(WiFi.status() != WL_CONNECTED){
     WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network. Change this line if using open or WEP network
     Serial.print(".");
     delay(5000);     
   } 
   Serial.println("\nConnected");
 }

readDoorChannel();
 
 delay(15000); // No need to read the counter too often.
 
}

void readDoorChannel(void) {
 int statusCode;
 
 // Read in field 1 of the private channel which is a counter  
 long doorSignal = ThingSpeak.readLongField(counterChannelNumber, counterFieldNumber, myCounterReadAPIKey);  

  // Check the status of the read operation to see if it was successful
 statusCode = ThingSpeak.getLastReadStatus();
 if(statusCode == 200){
   Serial.println("Counter: " + String(doorSignal));
 }
 else{
   Serial.println("Problem reading channel. HTTP error code " + String(statusCode)); 
 }

}
