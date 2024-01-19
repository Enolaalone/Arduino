int abPin=3;//数据输入角
int cpPin=2;//时钟脉冲角
int k=9;

int nums[]={0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6,0x02,0x00};//十六进制最简数组
void bin(int n)//转传二进制
{
  int mask=1<<7;//检测码 1000 0000
  
  for(int i=0;i<8;i++)
  {
    if (n & mask)//如果是高信号
    {
      //Serial.println(1);
      digitalWrite(abPin,HIGH);
       digitalWrite(cpPin,HIGH);//脉信号
     //Serial.println(123);
     digitalWrite(cpPin,LOW);
    }
    else//低信号
    {
      //Serial.println(0);
      digitalWrite(abPin,LOW);
       digitalWrite(cpPin,HIGH);//脉信号
   //Serial.println(123);
   digitalWrite(cpPin,LOW);
    }
    mask>>=1;//向左移动一位
    
   
  }
  
}

void setup() {
  // put your setup code here, to run once:

  pinMode(abPin,OUTPUT);
  pinMode(cpPin,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
   bin(nums[11]);
  if (k>=0)
  {
    bin(nums[k]);
    bin(nums[11]);
    bin(nums[11]);
    bin(nums[11]);
    delay(1000);
    k-=1;
  }
  else{
    bin(nums[10]);
     bin(nums[11]);
    bin(nums[11]);
    bin(nums[11]);
    delay(1000);
    bin(nums[11]);
    bin(nums[11]);
    bin(nums[11]);
    bin(nums[11]);
    delay(1000);
  }


 




  
  }
