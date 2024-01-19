int n=0;//计数
int nums[]={0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6,0x02,0x00};//十六进制最简数组0-9
int output[]={0,1,2,3,4,5,6,7,8,9};//时钟脉冲角or数据输入角
void bin(int n,int pin,int cp)//转传二进制
{
  int mask=1<<7;//检测码 1000 0000
  
  for(int i=0;i<8;i++)
  {
    if (n & mask)//如果是高信号
    {
      //Serial.println(1);
      digitalWrite(pin,HIGH);
      //Serial.println(1);
    }
    else//低信号
    {
      //Serial.println(0);
      digitalWrite(pin,LOW);
      //Serial.println(0);
    }
    mask>>=1;//向左移动一位
    
    digitalWrite(cp,HIGH);//脉信号
   //Serial.println(123);
   digitalWrite(cp,LOW);
  }
  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=2;i<10;i++)
  {
    pinMode(i,OUTPUT);
  }


}

void loop() {
  // put your main code here, to run repeatedly:
  int g=n%10;//个位
  int s=(n/10)%10;//十位
  int b=(n/100)%10;//百位
  int q=(n/1000)%10;//千位
  if(n>9999)
  {
    n=0;
  }
  if(n==0)
  {
   bin(nums[0],output[3],output[2]);//个
   bin(nums[0],output[5],output[4]);//十
   bin(nums[0],output[7],output[6]);//百
   bin(nums[0],output[9],output[8]);//千

   delay(1000);
  }
  else
  {
    if (n>0 && n<=9)
    {
      bin(nums[g],output[3],output[2]);//个
      bin(nums[11],output[5],output[4]);//十
      bin(nums[11],output[7],output[6]);//百
      bin(nums[11],output[9],output[8]);//千
      delay(100);
      Serial.println(1234);
 
    }
    else if(n>=10 && n<=99)
    {
      bin(nums[g],output[3],output[2]);//个
      bin(nums[s],output[5],output[4]);//十
      bin(nums[11],output[7],output[6]);//百
      bin(nums[11],output[9],output[8]);//千
      delay(10);
    }
    else if (n>=100 && n<=999)
    {
      bin(nums[g],output[3],output[2]);//个
      bin(nums[s],output[5],output[4]);//十
      bin(nums[b],output[7],output[6]);//百
      bin(nums[11],output[9],output[8]);//千
      delay(10);
 
    }
    else if (n>=1000 && n<=9999)
    {
      bin(nums[g],output[3],output[2]);//个
      bin(nums[s],output[5],output[4]);//十
      bin(nums[b],output[7],output[6]);//百
      bin(nums[q],output[9],output[8]);//千
      delay(10);

    }
 
  }
  n++;
  


}
