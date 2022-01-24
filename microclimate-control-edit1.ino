#include "DHT.h"
#include "LiquidCrystal.h"

#define DHTPIN 8 //pin en el que se conecta el sensor
#define DHTTYPE DHT11 //sensor utilizado dentro de la librería DHT.h

DHT dht(DHTPIN, DHTTYPE); 

int vent = 10; //pin en el que se conecta el ventilador
int bump = 9;
int lamp = 7;

LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
    Serial.begin(9600);
    pinMode(vent, OUTPUT);
    pinMode(bump,OUTPUT);
    pinMode(lamp,OUTPUT);
    dht.begin(); //se inicializa la librería del sensor
    lcd.begin(16,2);
}

void loop()
{
delay(2000);
 float h = dht.readHumidity(); //variable de lectura de la humedad a través del sensor
 float t = dht.readTemperature(); //variable de lectura de la temperatura
 float f = dht.readTemperature(true);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Hum. : "); //mensajes que se muestran en el terminal virtual con los valores medidos
 lcd.print(h);
 lcd.print("%");
 lcd.setCursor(0,1);
 lcd.print("Temp. : ");
 lcd.print(t);
 lcd.print("C");
  

  if(h>=90 && t>=27) //condiciones por fuera del óptimo para el cultivo de tomate
  {
    digitalWrite(vent,HIGH); 
    digitalWrite(lamp,LOW);
    digitalWrite(bump,LOW);
  }
    if (h<90 && t>=27) 
    {
    digitalWrite(bump,HIGH);
    digitalWrite(vent,LOW);
    digitalWrite(lamp,LOW);
    }
    if(t<27) //condiciones por fuera del óptimo para el cultivo de tomate
  {
    digitalWrite(lamp,HIGH); 
    digitalWrite(bump,LOW);
    digitalWrite(vent,LOW);
  delay(500);
}
}
