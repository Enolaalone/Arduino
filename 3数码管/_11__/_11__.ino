int num[][7]={{8,2,3,5,7,9},{7,5},{9,7,6,2,3},{9,7,6,5,3},{8,6,7,5},{9,8,6,5,3},{9,8,6,5,3,2},{9,7,5},{2,3,5,6,7,8,9},{6,8,9,7,5,3}};
int numLength[]={6,2,5,5,4,5,6,3,7,6};//数组长
//0--9
void setup() {
  // put your setup code here, to run once:
  for(int i=2;i<12;i++)
  {
    pinMode(i,OUTPUT);
  }
  //10，11端口模拟为w接地端
  Serial.begin(9600);

}

void number(int n)
{
  int n0;
  int n1;
  n1=n/10; //十位数
  n0=n%10; //个位数
  //Serial.println(n0);
  //Serial.println(n1);

  for(int i=0;i<numLength[n0];i++)//按照每个数的长度
  {
   digitalWrite(num[n0][i],HIGH);//打印对应数字的数组
  }
  delay(1000);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  number(10);
    
  }




