#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float V=0;
float sensorValue=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
   lcd.begin(16, 2);//16列2行
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(A0);
//  Serial.println(sensorValue);
  V=5*sensorValue/1023;
  Serial.println(V);
  lcd.setCursor(6,0);
  lcd.print(V);
  lcd.print("v");
  delay(100);
  lcd.clear();
}
