#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
    lcd.setCursor(15, 0);//从左到右表示列0-15，从上到下行0-1
    for(int i=0;i<16;i++)
   {
    lcd.rightToLeft();
    lcd.print("=");
    delay(500);
   }
   lcd.setCursor(0, 1);
    for(int i=0;i<16;i++)
   {
    lcd.leftToRight();
    lcd.print("=");
    delay(500);
   }
   lcd.clear();
}
