int ab1Pin=3;//数据输入角
int cp1Pin=2;//时钟脉冲角
int GND=4;//数码管阴极控制角
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
  pinMode(cp1Pin,OUTPUT);
  pinMode(GND,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
   int g=n%10;//个位
   int s=(n/10)%10;//十位
   if(n==0)
   {
    digitalWrite(GND,HIGH);
    bin(nums[g],ab1Pin,cp1Pin);//个位显示
    bin(nums[11],ab1Pin,cp1Pin);//十位显示
    bin(nums[11],ab1Pin,cp1Pin);
    bin(nums[11],ab1Pin,cp1Pin);
    digitalWrite(GND,LOW);
    delay(1000);
   }
   else 
   {
    if (n>0 && n<=9)
    {
      digitalWrite(GND,HIGH);//5v-5v熄灭数据传输
      bin(nums[g],ab1Pin,cp1Pin);//个位显示
      bin(nums[11],ab1Pin,cp1Pin);//十位熄灭
      bin(nums[11],ab1Pin,cp1Pin);
      bin(nums[11],ab1Pin,cp1Pin);
      digitalWrite(GND,LOW);//数据传输结束，显示
      delay(200);
    }
    else
    {
      digitalWrite(GND,HIGH);
      bin(nums[g],ab1Pin,cp1Pin);//个位显示
      bin(nums[s],ab1Pin,cp1Pin);//十位熄灭
      bin(nums[11],ab1Pin,cp1Pin);
      bin(nums[11],ab1Pin,cp1Pin);
      digitalWrite(GND,LOW);
      delay(200);
    }
    
   }
   
   n++;
   
}

