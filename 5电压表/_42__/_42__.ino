#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','x'},
  {'C','0','=','/'}
};
char a[]={'0','1','2','3','4','5','6','7','8','9'};
byte rowPins[ROWS] = {2,3,4,5}; //
byte colPins[COLS] = {9,8,7,6}; //
int A=0;
int B=0;
int answer=0;
int k=0;
int l=1;
bool Ak=false;
bool start=true;
char key;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
}

void set(int i)
{
   if (key==a[i])
  {
    if(Ak)
    {
      B=B*10;
      B+=i;
      Serial.println(B);
    }
    else
    {
      A=A*10;
      A+=i;
      Serial.println(A);
    }
  }
}
void calculate()
{
  if(k==1){
    answer=A+B;
  }
  else if(k==2){
    answer=A-B;
  }
  else if(k==3){
    answer=A*B;
  }
  else if(k==4){
    answer=A/B;
  }
}
void loop(){
//  Serial.println(A);
  if(key=='C')
  {
    A=0;
    B=0;
    k=0;
    answer=0;
    Ak=false;
    start=true;
  }
  key = keypad.getKey();
  if(start){
  set(0);
  set(1);
  set(2);
  set(3);
  set(4);
  set(5);
  set(6);
  set(7);
  set(8);
  set(9);
  if (key=='='){
    start=false;
    Serial.println(answer);
  }

  if(key=='+'){
    k=1;
    Ak=true;
  }
  else if(key=='-'){
    k=2;
    Ak=true;
  }
  else if(key=='x'){
    k=3;
    Ak=true;
  }
  else if(key=='/'){
    k=4;
    Ak=true;
  }
  calculate();
  }

}
