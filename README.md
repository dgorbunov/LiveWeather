# LiveWeather
Utilizes Arduino taking data from DHT11 and displaying on a 16x2 LCD, passed to Raspberry Pi over USB, Pi fetches the data from the serial connection, does some processing, and sends it out to Adafruit IO servers. Automated with crontab.

You can either use it together with a wifi enabled computer or a Raspberry Pi over USB (code for this in the Standard folder) or standalone with a NodeMCU
