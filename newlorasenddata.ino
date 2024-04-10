// #include <TinyGPS++.h//>


#include <heltec.h>

#include <Wire.h>  
#include "HT_SSD1306Wire.h"
#include <Firebase_ESP_Client.h>
#include <ArduinoJson.h>
SSD1306Wire  factory_display(0x3c, 500000, SDA_OLED, SCL_OLED, GEOMETRY_128_64, RST_OLED); // addr , freq , i2c group , resolution , rst


#define WIFI_SSID "Mushi Home"
// #define WIFI_PASSWORD "20002000"
#define WIFI_PASSWORD "12345678"


#include <addons/TokenHelper.h>

/* 2. Define the API Key */
#define API_KEY "AIzaSyB7s-Lzzk6IEV6XC3Y6Ojte4hTMGV7JpcM"

/* 3. Define the project ID */
#define FIREBASE_PROJECT_ID "smart-garbage-collection-8fb03"

/* 4. Define the user Email and password that alreadey registerd or added in your project */

#define USER_EMAIL "esp8266@gmail.com"
#define USER_PASSWORD "123456"

void VextON(void)
{
  pinMode(Vext,OUTPUT);
  digitalWrite(Vext, LOW);
}

void VextOFF(void) //Vext default OFF
{
  pinMode(Vext,OUTPUT);
  digitalWrite(Vext, HIGH);
}


void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);
	VextON();
	delay(100);
	factory_display.init();
	factory_display.clear();
	factory_display.display();

	pinMode(LED ,OUTPUT);
	digitalWrite(LED, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
 
  factory_display.clear();
  factory_display.display();  
  factory_display.setFont(ArialMT_Plain_10);
  factory_display.setTextAlignment(TEXT_ALIGN_CENTER);
  factory_display.drawString(64, 0, "Current Reading");
  factory_display.setTextAlignment(TEXT_ALIGN_LEFT);
  factory_display.drawString(0, 10, "Sensor One");
  factory_display.setTextAlignment(TEXT_ALIGN_RIGHT);
  factory_display.drawString(128, 10, "1234.50");
  factory_display.setTextAlignment(TEXT_ALIGN_LEFT);
  factory_display.drawString(0, 20, "Sensor Two");
  factory_display.setTextAlignment(TEXT_ALIGN_RIGHT);
  factory_display.drawString(128, 20, "543.21");  
  factory_display.display();
  delay(5000);
  factory_display.clear();
  factory_display.display();       
  factory_display.setFont(ArialMT_Plain_10);
  factory_display.setTextAlignment(TEXT_ALIGN_LEFT);
  factory_display.drawStringMaxWidth(0, 0, 128,"I have been many years training in the Way of Strategy, called Ni Ten Ichi Ryu, and now I think I will explain it in writing for the first time." );
  factory_display.display();
  delay(5000);
}
