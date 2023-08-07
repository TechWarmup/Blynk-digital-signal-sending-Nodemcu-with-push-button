#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>



char auth[] = "Lgbkq75yTIUwlPEaBBQBzprEsckXdHus"; // Enter your Auth Token 


char ssid[] = "OnePlus 10 Pro 5G"; // Enter your WIFI name
char pass[] = "12121212"; // Enter your WIFI password
int Button =D3;


WidgetLED led1(V0);
BlynkTimer timer;

void button_status()
{
  int value =digitalRead(Button);
  if(value==HIGH)
  { led1.on();
  }
  else{
    led1.off();
  }
   }

void setup() {
  Serial.begin(115200); 
  //Set the Relay pins as an output
  pinMode(Button, INPUT); 

  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  timer.setInterval(300L,button_status);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
  timer.run();
}
