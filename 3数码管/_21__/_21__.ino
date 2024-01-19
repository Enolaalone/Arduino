int Pin4=9;//个位
int Pin3=10;//十位
int Pin2=11;//百位
int Pin1=12;//千位
int n=0;


int numbers[10][7]={{1, 1, 1, 1, 1, 1, 0}, 
                    {0, 1, 1, 0, 0, 0, 0}, 
                    {1, 1, 0, 1, 1, 0, 1}, 
                    {1, 1, 1, 1, 0, 0, 1}, 
                    {0, 1, 1, 0, 0, 1, 1}, 
                    {1, 0, 1, 1, 0, 1, 1}, 
                    {1, 0, 1, 1, 1, 1, 1}, 
                    {1, 1, 1, 0, 0, 0, 0},
                    {1, 1, 1, 1, 1, 1, 1},
                    {1, 1, 1, 1, 0, 1, 1}};//0-9

void num(int ls[])//打印数字
{
  for(int i=0;i<7;i++)
  {
    if(ls[i]==1)
    {
      digitalWrite(i+2,HIGH);//亮
      //Serial.println(i+2);
    }
    else
    {
      digitalWrite(i+2,LOW);//灭
    }
  }
}


void setup() {
  // put your setup code here, to run once:
  for (int i=2;i<13;i++)
  {
    pinMode(i,OUTPUT);
  }
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int g=n%10;//个位
  int s=(n/10)%10;//十位
  int b=(n/100)%10;//百位
  int q=(n/1000)%10;//百位
  if(n==0)
  {
    num(numbers[0]);
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin2, LOW);
    digitalWrite(Pin3, LOW);
    digitalWrite(Pin4, LOW);
    delay(1000);
    
  }
  else
  {
    //for (int j=0;j<5;j++)//反复显示达到持续存在的效果
    //{
      if(n<=9999)
     {
      num(numbers[g]);
      digitalWrite(Pin4,LOW);
      digitalWrite(Pin3,HIGH);
      digitalWrite(Pin2,HIGH);
      digitalWrite(Pin1,HIGH);
      delay(1);
      num(numbers[s]);
      digitalWrite(Pin4,HIGH);
      digitalWrite(Pin3,LOW);
      digitalWrite(Pin2,HIGH);
      digitalWrite(Pin1,HIGH);
      delay(1); 
      num(numbers[b]);
       digitalWrite(Pin4,HIGH);
      digitalWrite(Pin3,HIGH);
      digitalWrite(Pin2,LOW);
      digitalWrite(Pin1,HIGH);
      delay(1); 
      num(numbers[q]);
       digitalWrite(Pin4,HIGH);
      digitalWrite(Pin3,HIGH);
      digitalWrite(Pin2,HIGH);
      digitalWrite(Pin1,LOW);
      delay(1); 
     }
     else
     {
      n=0;
     }
    //}
  }
  
n++;
}
