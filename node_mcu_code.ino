#include <BearSSLHelpers.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <CertStoreBearSSL.h>
#include <DNSServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h> 
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiManager.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>

#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN D7
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int THRESHOLD = 380;
int pinRedLed = D1;
int pinGreenLed = D2;
int pinSensor = A0;
int buzzer = D3;
int rdata = 0;
char mystring[20];

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(buzzer, OUTPUT);
  pinMode(pinRedLed, OUTPUT);
  pinMode(pinGreenLed, OUTPUT);
  pinMode(pinSensor, INPUT);

  WiFiManager wifiManager;
  wifiManager.autoConnect("NodeMCU");

  Serial.println("Connected to WiFi");
}

void loop() {
  rdata  =  analogRead(pinSensor);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  

  Serial.print("Ethylene Range: ");
  Serial.println(rdata);

  if (rdata >= THRESHOLD) {
    digitalWrite(pinRedLed, HIGH);
    digitalWrite(pinGreenLed, LOW);
    digitalWrite(buzzer, HIGH);
    delay(2000);
  } else
  {
    digitalWrite(pinRedLed, LOW);
    digitalWrite(pinGreenLed, HIGH);
    digitalWrite(buzzer, LOW);
  }

  if (rdata < 380) {
    sprintf(mystring, "Ethylene Range: %d", rdata);
    Serial.println(mystring);
  } else
  {
    strcpy(mystring, "Ripened");
    Serial.println(mystring);
  }

  memset(mystring, 0, sizeof(mystring));

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }


  

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");


  // print temperature and humidity to LCD display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");

  delay(2000);
}

