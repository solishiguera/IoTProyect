#include <ESP8266WiFi.h>

#include "DHT.h"
#define DHTTYPE DHT11
#define dht_dpin 0

DHT dht(dht_dpin, DHTTYPE);

int sensorPin = D3;
int PWM = 3;
int sensorVal;
int PWMVal;


void setup() {
//  WiFi.begin(ssid, password);
//  while (WiFi.status() != WL_CONNECTED){ 
//    delay(500);
//    Serial.print(".");
//  }

//  Serial.println("");
//  Serial.println("WiFi Connected");
//  Serial.println("IP address: ");
//  Serial.println(WiFi.localIP());

  
  dht.begin();
  Serial.begin(9600);
  Serial.println("Humedad y Temperatura\n\n");
  delay(700);

  pinMode(sensorPin, INPUT);
  pinMode(PWM, OUTPUT);
}


void loop() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    Serial.print("Humedad = ");
    Serial.print(h);
    Serial.print("%   ");
    Serial.print("Temperatura = ");
    Serial.print(t);
    Serial.println("'C   ");
  delay(800);
  
  sensorVal = t;
  PWMVal = map(sensorVal, 0, 30, 0, 255);
  
  analogWrite(PWM, PWMVal);
}
