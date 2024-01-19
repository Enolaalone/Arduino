int abPin=3;//数据输入角
int cpPin=2;//时钟脉冲角
int k=9;

int nums[]={0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6,0x02,0x00};//十六进制最简数组
void bin(int n0,int n1,int n2,int n3)//转传二进制
{
  int arr[4]={n0,n1,n2,n3};
  int sign[32]={0};
  for(int j=0;j<4;j++)
  {
     int mask=1<<7;//1左移7位检测码 1000 0000
     for(int i=0;i<8;i++)
    {
      if (arr[j] & mask)//如果是高信号
      {
        sign[i+j*8]=1;
      }
      else//低信号
      {
        sign[i+j*8]=0;
      }
      mask>>=1;//向右移动一位
   }

  }
  for(int i=0;i<32;i++)
  {
    if (sign[i]==1)
    {
     digitalWrite(abPin,HIGH);
    }
    else
    {
       digitalWrite(abPin,LOW);
    }
    digitalWrite(cpPin,HIGH);//脉信号
   //Serial.println(123);
   digitalWrite(cpPin,LOW);
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
  if (k>=0)
  {
    bin(nums[k],nums[11],nums[11],nums[11]);
    delay(1000);
    k-=1;
  }
  else{
    bin(nums[10],nums[11],nums[11],nums[11]);
    delay(1000);
    bin(nums[11],nums[11],nums[11],nums[11]);
    delay(1000);
  }


 




  
  }
