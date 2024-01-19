int n=0;//计数
int nums[]={0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6,0x02,0x00};//十六进制最简数组0-9
int output[]={0,1,2,3,4,5,6};//时钟脉冲角or数据输入角 and 5,6按钮控制
int Button1=5;
int Button1Status=0;
int Button2=6;
int Button2Status=0;
int k=1; //选位计数
int g=0;//个位
int s=0;//十位
int b=0;//百位
int q=0;//千位
unsigned long lasttime=0;
unsigned long delaytime=3000;
unsigned long t0=0;
unsigned long t1=0;

bool pressed=false;
bool start=false;//是否开始
bool record=false;
bool change=false;//选位数字亮或灭

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

void super_bin(int n1,int n2,int n3,int n4,int tm)
{
  digitalWrite(output[4],HIGH);
  bin(nums[n4],output[3],output[2]);//个
  bin(nums[n3],output[3],output[2]);//十
  bin(nums[n2],output[3],output[2]);//百
  bin(nums[n1],output[3],output[2]);//千
  digitalWrite(output[4],LOW);
  delay(tm);
}


void select_bin(int n1,int n2,int n3,int n4,int t)//延时不影响主函数
{
  t0=millis();
  Serial.println(t0);
  Serial.println(t1);
  if(t0-t1<=t)
  {
    digitalWrite(output[4],HIGH);
    bin(nums[n4],output[3],output[2]);//个
    bin(nums[n3],output[3],output[2]);//十
    bin(nums[n2],output[3],output[2]);//百
    bin(nums[n1],output[3],output[2]);//千
    digitalWrite(output[4],LOW);
  }
  else
  {
    t1=t0;
    change=!change;
  }
}

void Blink(int n1,int n2,int n3,int n4,int t)//闪烁
{
  if(!change)
  {
    select_bin(q,b,s,g,1000);//个位亮起
  }
  else{
    select_bin(n1,n2,n3,n4,1000);//个位熄灭
  }  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=2;i<5;i++)
  {
    pinMode(i,OUTPUT);
  }
  pinMode(Button1,INPUT_PULLUP);//高电位 选数字键 长按选位
  pinMode(Button2,INPUT_PULLUP);//       确定键

}

void loop() {
  // put your main code here, to run repeatedly:
    g=n%10;//个位
    s=(n/10)%10;//十位
    b=(n/100)%10;//百位
    q=(n/1000)%10;//千位

  if(start)
  {
      if(n>9999)
      {
        n=0;
      }
      if(n==0)
      {
       super_bin(11,11,11,0,1000);
      }
      else
      {
        if (n>0 && n<=9 )
        {
          super_bin(11,11,11,g,1000);
        }
        else if(n>=10 && n<=99)
        {
          super_bin(11,11,s,g,10);
        }
        else if (n>=100 && n<=999)
        {
          super_bin(11,b,s,g,10);
        }
        else if (n>=1000 && n<=9999)
        {
          super_bin(q,b,s,g,10);
        }
      }
      n++;
  }
  else
  {
    //Serial.println(Button1Status);
    Button1Status=digitalRead(Button1);
    Button2Status=digitalRead(Button2);
    if(!Button2Status)//开始
    {
      start=true;
    }
    
    if (!Button1Status)//!0
    {
      if (!pressed)
      {
        lasttime=millis();
      }
      pressed=true;//按下-------------------------

      if (millis()-lasttime>delaytime && !record)
      { 
        record=true;//已经记录
        k+=1;
        if (k>4)
        {
          k=1;
        }
//        Serial.print("k的值");
//        Serial.println(k);
      }
      //else if(!record && )//小于3s

      
    }
    
    if(Button1Status)
    {
      if (pressed && !record)
      {
        if(k==1)
        {
          g+=1;
          if (g>=10)
          {
            g=0;
          }
        }
        else if(k==2)
        {
          s+=1;
          if (s>=10)
          {
            s=0;
          }
        }
        else if(k==3)
        {
          b+=1;
          if (b>=10)
          {
            b=0;
          }
        }
        else if(k==4)
        {
          q+=1;
          if (q>=10)
          {
            q=0;
          }
        }
//        Serial.print("g的值");
//        Serial.println(g);
//        Serial.println();
//        Serial.print("s的值");
//        Serial.println(s);
//         Serial.println();
//        Serial.print("b的值");
//        Serial.println(b);
//         Serial.println();
//        Serial.print("q的值");
//        Serial.println(q);
//         Serial.println();
      }
      pressed=false;//还原
      record=false;
    }
      if(k==1)
      {
        Blink(q,b,s,11,600);//个位闪烁
      }
      else if(k==2)
     {
      Blink(q,b,11,g,600);//十位闪烁
     }
     else if(k==3)
     {
       Blink(q,11,s,g,600);//百位闪烁
     }
    else if(k==4)
    {
      Blink(11,b,s,g,600);//千位闪烁
    }
    
    n=1000*q+100*b+10*s+g;//n的值
  }

  

  


}
