namespace VS_ESP01_GUI
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.SerialStart = new System.Windows.Forms.Button();
            this.SerialStop = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.SuspendLayout();
            // 
            // SerialStart
            // 
            this.SerialStart.Location = new System.Drawing.Point(59, 91);
            this.SerialStart.Name = "SerialStart";
            this.SerialStart.Size = new System.Drawing.Size(180, 71);
            this.SerialStart.TabIndex = 0;
            this.SerialStart.Text = "Serial Start";
            this.SerialStart.UseVisualStyleBackColor = true;
            this.SerialStart.Click += new System.EventHandler(this.SerialStart_Click);
            // 
            // SerialStop
            // 
            this.SerialStop.Location = new System.Drawing.Point(376, 91);
            this.SerialStop.Name = "SerialStop";
            this.SerialStop.Size = new System.Drawing.Size(175, 71);
            this.SerialStop.TabIndex = 1;
            this.SerialStop.Text = "Serial Stop";
            this.SerialStop.UseVisualStyleBackColor = true;
            this.SerialStop.Click += new System.EventHandler(this.SerialStop_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(59, 197);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(180, 72);
            this.button3.TabIndex = 2;
            this.button3.Text = "Read in TS Channel";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.Read_in_channel_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(436, 234);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(44, 16);
            this.label1.TabIndex = 3;
            this.label1.Text = "label1";
            this.label1.Click += new System.EventHandler(this.Form1_Load);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(129, 341);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(81, 16);
            this.label2.TabIndex = 4;
            this.label2.Text = "Current Data";
            this.label2.Click += new System.EventHandler(this.Current_data_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(407, 341);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 22);
            this.textBox1.TabIndex = 5;
            this.textBox1.Click += new System.EventHandler(this.textBox1_TextChanged);
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 10000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // serialPort1
            // 
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.SerialPort1_DataReceived);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.SerialStop);
            this.Controls.Add(this.SerialStart);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button SerialStart;
        private System.Windows.Forms.Button SerialStop;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Timer timer1;
        private System.IO.Ports.SerialPort serialPort1;
    }
}

