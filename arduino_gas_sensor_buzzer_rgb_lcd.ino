
//Written by Emin Ayyıldız

#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int red_led = 6;
int green_led = 7;
int gas_sensor = A0;
int buzzer = 13;
#define red 8
#define green 10
#define blue 9
#define Si  494

void setup()
{
  
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(gas_sensor,OUTPUT);
  lcd.begin(16, 2); 
  lcd.setCursor(0,1);
  
}

void loop()
{ 
  int gas_sensor = analogRead(gas_sensor); 
  
  Serial.print("Gas sensor value : ");
  Serial.println(gas_sensor);
  if (gas_sensor <= 15)
  {  
    Serial.println("System is not activated");
    lcd.setCursor(0,0);          
    lcd.print("Gas Sensor Value :");
    lcd.setCursor(0,1);
    lcd.print(gas_sensor);
    delay(700);
    lcd.clear();
    delay(200);
  	digitalWrite(red_led, LOW);
  	digitalWrite(green_led,HIGH);
  	noTone(buzzer);

  	digitalWrite(red,0);
  	delay(100);
  	digitalWrite(blue,0);
  	
  	digitalWrite(green,255);
    delay(500);
    digitalWrite(green,0);
    delay(100);
  }
  else
  { 
    lcd.setCursor(0,0);
    lcd.print("Gas Sensor Value :");
    lcd.setCursor(0,1);
    lcd.print(gas_sensor);
    lcd.clear();
    delay(250);
    lcd.print("Alarm Activated");
    lcd.setCursor(0,1);
    lcd.print(gas_sensor);
              
 
    Serial.println("System is activated");
    digitalWrite(red_led,HIGH);
    digitalWrite(green_led,LOW);
    tone(buzzer, Si);
    digitalWrite(red,255);
    delay(250);
    digitalWrite(red,0);
    digitalWrite(blue,255);
    delay(250);
    digitalWrite(blue,0);
    
    }
}
