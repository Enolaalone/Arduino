int ab2Pin=5;//数据输入角
int ab1Pin=3;//数据输入角
int cp1Pin=2;//时钟脉冲角
int cp2Pin=4;//时钟脉冲角
int n=0;

int nums[]={0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6,0x02,0x00};//十六进制最简数组
void bin(int n,int pin,int cp)//转传二进制
{
  int mask=1<<7;//检测码 1000 0000
  
  for(int i=0;i<8;i++)
  {
    if (n & mask)//如果是高信号
    {
      //Serial.println(1);
      digitalWrite(pin,HIGH);

    }
    else//低信号
    {
      //Serial.println(0);
      digitalWrite(pin,LOW);
 
    }
    mask>>=1;//向左移动一位
    
    digitalWrite(cp,HIGH);//脉信号
   //Serial.println(123);
   digitalWrite(cp,LOW);
  }
  
}

void setup() {
  // put your setup code here, to run once:

  pinMode(ab1Pin,OUTPUT);
  pinMode(ab2Pin,OUTPUT);
  pinMode(cp1Pin,OUTPUT);
  pinMode(cp2Pin,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
   int g=n%10;//个位
   int s=(n/10)%10;//十位
   if(n==0)
   {
    bin(nums[g],ab1Pin,cp1Pin);//个位显示
    bin(nums[11],ab2Pin,cp2Pin);//十位显示
    delay(1000);
   }
   else 
   {
    if (n>0 && n<=9)
    {
      bin(nums[g],ab1Pin,cp1Pin);//个位显示
      bin(nums[11],ab2Pin,cp2Pin);//十位熄灭
      delay(200);
    }
    else
    {
      bin(nums[g],ab1Pin,cp1Pin);//个位显示
      bin(nums[s],ab2Pin,cp2Pin);//十位熄灭
      delay(200);
    }
    
   }
   
   n++;
   
}

