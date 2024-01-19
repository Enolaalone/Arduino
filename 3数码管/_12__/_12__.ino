int Pin3=9;//个位
int Pin1=10;//十位
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
  for (int i=2;i<11;i++)
  {
    pinMode(i,OUTPUT);
  }
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int g=n%10;//个位
  int s=(n/10)%10;//十位
  if(n==0)
  {
    num(numbers[0]);
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin3, LOW);
    delay(1000);
    
  }
  else
  {
    for (int j=0;j<20;j++)//反复显示达到持续存在的效果
    {
      if(n<=99)
     {
      num(numbers[g]);
      digitalWrite(Pin1,HIGH);
      digitalWrite(Pin3,LOW);
      delay(5);
      num(numbers[s]);
      digitalWrite(Pin3,HIGH);
      digitalWrite(Pin1,LOW);
      delay(5); 
     }
     else
     {
      n=0;
     }
    }
  }
  
n++;
}
