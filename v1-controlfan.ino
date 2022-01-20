#include "DHT.h"

#define DHTPIN 8 //pin en el que se conecta el sensor
#define DHTTYPE DHT11 //sensor utilizado dentro de la librería DHT.h

DHT dht(DHTPIN, DHTTYPE); 

int vent = 7; //pin en el que se conecta el ventilador

void setup()
{
    Serial.begin(9600);
    pinMode(vent, OUTPUT);
    dht.begin(); //se inicializa la librería del sensor
}

void loop()
{
delay(2000);
 float h = dht.readHumidity(); //variable de lectura de la humedad a través del sensor
 float t = dht.readTemperature(); //variable de lectura de la temperatura
 float f = dht.readTemperature(true);
 Serial.println("Humedad relativa: "); //mensajes que se muestran en el terminal virtual con los valores medidos
 Serial.println(h);
 Serial.println("%");
 Serial.println("Temperatura: ");
 Serial.println(t);
 Serial.println("grados centigrados");
  

  if((h>=90) || (t>=27)) //condiciones por fuera del óptimo para el cultivo de tomate
  {
    digitalWrite(vent,HIGH); 
  }
  else
  {
    digitalWrite(vent,LOW);
  }
  
  delay(500);
}
