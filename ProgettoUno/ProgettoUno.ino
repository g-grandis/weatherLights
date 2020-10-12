#include <MQTT.h>
#define BROKER_IP    "192.168.1.232"
#define DEV_NAME     "mqttdevice"
#define MQTT_USER    "user"
#define MQTT_PW      "password"

#ifdef ARDUINO_SAMD_MKRWIFI1010
#include <WiFiNINA.h>
#elif ARDUINO_SAMD_MKR1000
#include <WiFi101.h>
#elif ESP8266
#include <ESP8266WiFi.h>
#else
#error unknown board
#endif

#define PIXEL_COUNT 20
#define PIXEL_PIN    0
#include "Adafruit_NeoPixel.h"
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
const int button = 6;
WiFiClient net;
MQTTClient client;


/*    VARIABILI   */
int value;
int stateLED = LOW;
int stateButton;
int previous = HIGH;
long time = 0;
long debounce = 200;
int on = 0;
unsigned long lastMillis = 0;
String weather;
boolean done = false;
const char ssid[] = "FASTWEB-E1784722";
const char pass[] = "TP2Z7C1P48";


void setup()
{
  pinMode(button,INPUT);
  strip.begin();
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  client.begin(BROKER_IP, 1883, net);
  client.onMessage(messageReceived);
  connect();
}
 
void loop()    
{
  client.loop(); 
  stateButton = digitalRead(button);
  if(stateButton == LOW && previous == HIGH && millis() - time > debounce)
  {
    if(stateLED == HIGH){
      stateLED = LOW;
      on = 0;
      On(on);
    }
    else
    {
      stateLED = HIGH;
      on = 1;
    }
    time = millis();
  }
  if(stateLED == HIGH){ 
    On(on);
  }
  previous = stateButton;
}


void On(int on)
{
  if (on==1){
    if(done == false){
      client.publish("/arduinoSendRequest", "turin"); //PUBLISH TO TOPIC /hello MSG world
      done=true;
    }
    int value = analogRead(A0);
      if (value > 100) {value = 100;}
      if (value < 5) {value = 5;}
    value = map(value,5, 100, 255, 0);
    strip.setBrightness(value);
    int color=weather.toInt();
    weatherLight(color);
  }
    else if (on==0)
    {
      strip.setBrightness(0);  
      strip.show();
      done=false;
    }  
}
