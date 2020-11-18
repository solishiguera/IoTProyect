#include <ESP8266WiFi.h>

#include "DHT.h"
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
#include <FirebaseObject.h>
#define DHTTYPE DHT11
#define dht_dpin 0

#define WIFI_SSID "XXXXXXX"
#define WIFI_PASSWORD "XXXXXXX"
#define FIREBASE_HOST "firebaseio.com"
#define FIREBASE_AUTH "XXXXXX"  

DHT dht(dht_dpin, DHTTYPE);

int sensorPin = D3;
int PWM = 3;
int sensorVal;
int PWMVal;


void setup() {
  Serial.begin(9600);

  Serial.println('\n');
    wifiConnect();

    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    if (Firebase.failed()) {
        Serial.print(F("setting number failed:"));
        Serial.println(Firebase.error());
    } else {
        Serial.println("Firebase connected ");
    }
  
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
    Firebase.setInt("Temperature",t);
    delay(800);
  
  sensorVal = t;
  PWMVal = map(sensorVal, 0, 30, 0, 255);
  
  analogWrite(PWM, PWMVal);
}


void wifiConnect() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);     //Conectar con la red WiFi
    int teller = 0;
    while (WiFi.status() != WL_CONNECTED) {   //Esperar por la conexión WiFi
        delay(1000);
        Serial.print(++teller); Serial.print(' ');
    }

} //End wifiConnect()
