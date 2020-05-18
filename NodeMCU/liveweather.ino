// edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi, cellular,
// or ethernet clients.
#include "config.h"
#include <Adafruit_Sensor.h>
#include "DHT.h"

// pin connected to DHT data line
#define DHTPIN 2
#define DHTTYPE DHT11

// create DHT22 instance
DHT dht(DHTPIN, DHTTYPE);

// set up the 'temperature' and 'humidity' feeds
AdafruitIO_Feed *temperature = io.feed("OutsideTemp");
AdafruitIO_Feed *humidity = io.feed("OutsideHumidity");
AdafruitIO_Feed *heatIndex = io.feed("OutsideHeatIndex");

void setup() {

  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  // initialize dht
  dht.begin();

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();

  float h = dht.readHumidity();
  float f = dht.readTemperature(true);
  float hif = dht.computeHeatIndex(f, h);

  if (not isnan(f) || not isnan(h)){
    temperature->save(f);
    humidity->save(h);
    heatIndex->save(hif);
  }
  // wait 5 seconds (5000 milliseconds == 5 seconds)
  delay(3000);

}
