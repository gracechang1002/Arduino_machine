#include<LiquidCrystal.h>
int i = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const byte SW = 8;
const byte SW2 = 9;

#LCD顯示器顯示
void steup( ){
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Number of Cars :");
    lcd.setCursor(0, 1);
    lcd.print(i);
    pinMode(8, INPUT);
}

#計算紅燈時接觸次數
void loop( ){
    byte val2 = digitalRead(SW2);
    if(val == 1){
       byte val = digitalRead(SW);
       if(val == 1){
          i++;
          lcd.setCurse(0, 1);
          lcd.print("i");
         delay(300);
    }
  }
}