# esp32-motion-logger

A very simple ESP32C3 motion sensor that sends instant telegram alerts when movement is detected. 

### Hardware:
- ESP32-C3 Supermini
- HC-SR501 PIR motion sensor
- Jumper wires

### Wiring:
```
ESP32-C3    HC-SR501
3.3V/5V   →  VCC
GPIO3     →  OUT  
GND       →  GND
```

### Setup
Create a bot in telegram through @BotFather, get your token and then chat ID through @userinfobot, and confugure the remaining credentials for WiFi/hotspot. 


### Possible future improvements
- Rewrite in ESP-IDF framework without Arduino for better performance and lower power consumption
- Storing detection time in a file and sending it to the bot whenever your ESP32 connects to a network, in order to reduce the deivces dependence on internet connectivity 
