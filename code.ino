#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
char auth[] = "your-auth-code"; //Enter Authentication code sent by Blynk
 

char ssid[] = "your-wifi-ssid"; //Enter WIFI Name
char pass[] = "your-wifi-password"; //Enter WIFI Password
 
SimpleTimer timer;
 
int mq6 = A0; // LPG sensor MQ -6 is connected with the analog pin A0 
int data = 0; 
void setup() 
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, getSendData);
}
 
void loop() 
{
  timer.run(); // Initiates SimpleTimer
  Blynk.run();
}
 
void getSendData()
{
data = analogRead(mq6); 
  Blynk.virtualWrite(V2, data); // Blynk INPUT Connect V2 Pin
 
  if (data > 700 )
  {
    Blynk.notify("LPG Detected!"); 
  }
 
}
