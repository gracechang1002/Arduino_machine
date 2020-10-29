#七段顯示器讀取矩陣
byte seven_seg_digits[10] = {B00000000,
		B01100000,   // = 1
		B11011010,   // = 2
		B11110010,   // = 3
		B01100110,   // = 4
		B10110110,   // = 5
		B10111110,   // = 6
		B11100000,   // = 7
		B11111110,   // = 8
		B11100110,   // = 9
		         }

const byte latchPin = 9;
const byte clockPin = 10;
const byte dataPin = 8;
const byte SW = 11;
const byte SW2 = 12;
const byte SW3 = 13;
int i;

void setup(){
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
}

#紅燈時的七段顯示器
void Red(byte digit){
         digitalWrite(latchPin, Low);
         shiftOut(dataPin, clockPin, LSBFIRST, seven_seg_digits[digit]);
         digitalWrite(latchPin,HIGH);

#綠燈時的七段顯示器
void Green(byte digit){
         digitalWrite(latchPin, Low);
         shiftOut(dataPin, clockPin, LSBFIRST, seven_seg_digits[digit]);
         digitalWrite(latchPin,HIGH);

#黃燈時關閉七段顯示器
void nothin( ){
         digitalWrite(latchPin, Low);
         shiftOut(dataPin, clockPin, LSBFIRST, seven_seg_digits[0]);
         digitalWrite(latchPin,HIGH);

#閃黃燈
void detect( ){
     nothing( );
     boolean val = digitalRead(SW);
     if(val==1){
      for(i = 0; i<100; i++){
        detect3( );
        if(i%2==0){
          digitalWrite(6,1);
          digitalWrite(5,0);
          digitalWrite(7,0);
          delay(700);
        }
        else{
          digitalWrite(6,0);
          digitalWrite(5,0);
          digitalWrite(7,0);
          delay(700);
        }
      }
     }
}

#閃紅燈
void detect2( ){
     nothing( );
     boolean val2 = digitalRead(SW2);
     if(val2==1){
      for(i = 0; i<100; i++){
        detect3( );
        if(i%2==0){
          digitalWrite(6,0);
          digitalWrite(5,1);
          digitalWrite(7,0);
          delay(700);
        }
        else{
          digitalWrite(6,0);
          digitalWrite(5,0);
          digitalWrite(7,0);
          delay(700);
        }
      }
     }
}

#初始紅綠燈
void detect3( ){
     boolean val3 = digitalRead(SW3);
     if(val3==1){
          digitalWrite(6,0);
          digitalWrite(5,1);
          digitalWrite(7,0);
          delay(1500);
          loop( );
        }
 }

#綠燈7秒
void loop( ){
   for (byte digit = 8; digit > 1; digit--){
          delay(1000);
          detect( );  
          detect2( );
          Green(digit - 1);
          digitWrite(7, 1);
          digitWrite(6, 0);
          digitWrite(5, 0);
          }
   deley(1000);

#黃燈2.5秒
   nothing( );
   detect( );  
   detect2( );
   digitWrite(6, 1);
   digitWrite(5, 0);
   digitWrite(7, 0);
   deley(1500);

#紅燈9秒
   for (byte digit = 10; digit > 1; digit--){
          delay(1000);
          detect( );  
          detect2( );
          Red(digit - 1);
          digitWrite(5, 1);
          digitWrite(6, 0);
          digitWrite(7, 0);
          }
   return loop( );
}








