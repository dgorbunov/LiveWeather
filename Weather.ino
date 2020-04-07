
#include <LiquidCrystal.h>

#include "DHT.h"
#define DHT1PIN 8
#define DHT2PIN 4

LiquidCrystal lcd(7, 13, 9, 10, 11, 12);

#define DHT1TYPE DHT11
#define DHT2TYPE DHT11

DHT dht1(DHT1PIN, DHT1TYPE);
DHT dht2(DHT2PIN, DHT2TYPE);


void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(16, 2);
  dht1.begin();
  dht2.begin();

}

void loop() {
  float hout = dht1.readHumidity();
  float tout = dht1.readTemperature();
  float hin = dht2.readHumidity();
  float tin = dht2.readTemperature();

  tout = tout * 9 / 5 + 32; //Celius to Fahrenheit
  tin = tin * 9 / 5 + 32; 
  
  if (isnan(tout) || isnan(hout)) {
    lcd.setCursor(0, 0);
    lcd.print("Read Failed");
    lcd.setCursor(0,1);
    lcd.print("From Outside");
  }
    if (isnan(tin) || isnan(hin)) {
    lcd.setCursor(0, 0);
    lcd.print("Read Failde");
    lcd.setCursor(0,1);
    lcd.print("From Inside");
  }
  else {
    Serial.print("Temp Out: ");
    Serial.print(tout);
    Serial.print("\t");
    Serial.print("Humidity Out: ");
    Serial.print(hout);
    Serial.println();
  
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Humidity: ");
    lcd.print(hout);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(tout);
    lcd.print("F");
    lcd.setCursor(13,1);
    lcd.print("out");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Humidity: ");
    lcd.print(hin);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(tin);
    lcd.print("F");
    lcd.setCursor(14,1);
    lcd.print("in");
    delay(3000);

  }
}
