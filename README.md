# LiveWeather
Utilizes Arduino taking data from DHT11 and displaying on a 16x2 LCD, passed to Raspberry Pi over USB, Pi fetches the data from the serial connection, does some processing, and sends it out to Adafruit IO servers. Automated with crontab.

# NodeMCU Setup
Navigate to the NodeMCU folder and install ESPTool to flash the chip's firmware. Run '\esptool --port <port> write_flash 0x00000 firmware.bin' to install AT commands, verify by sending the AT command to the NodeMCU via Serial Monitor.

- Migrate to ESP8266
- Use DHT22 for accuracy
- Get DarkSky conditions
- Publish inside data too?
- Axis labels
- 1Hz publishing
- Key + User files
- Don't force re-lib import
