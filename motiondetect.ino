#include <WiFi.h>
#include <HTTPClient.h>

#define PIN 3

char ssid[] = "";
char pass[] = "";
char botToken[] = "";
char chatId[] = "";

volatile bool detectionFlag = false;


void ISR()
{
  detectionFlag = true;  
}

void sendTelegram(String message){
  if(WiFi.status() == WL_CONNECTED){
    HTTPClient http;

    String url = "https://api.telegram.org/bot" + String(botToken) + 
                 "/sendMessage?chat_id=" + String(chatId) + 
                 "&text=" + message;
    
    http.begin(url);
    int httpCode = http.GET();
    
    http.end();
  }
}

void setup() 
{
  pinMode(PIN, INPUT);
  Serial.begin(115200);
  Serial.flush();
  attachInterrupt(digitalPinToInterrupt(PIN), ISR, RISING);

  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

}

void loop()
{
  if(detectionFlag)
  {
    Serial.println("Intruder detected - sending alert");
    sendTelegram("Warning! Intruder detected");
    detectionFlag = false;
    delay(10000);
  }
}



