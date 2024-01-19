int number[][10]={{3,2,4,5,8,7},{4,5,2,3,8,7,6},{4,5,8},{4,2,3,8,7,6},{4,2,3,8,7},{2,3,5,8},{4,5,3,8,7},{4,5,3,6,7},{5,8},{6,2,4,5,8,7},{3}};
int num[]={9,8,7,6,5,4,3,2,1,0};
int input_number[]={6,7,3,6,5,4,5,5,2,6,1};
bool endTime=false;//结束与否

void setup() {
  // put your setup code here, to run once:
  for(int i=2;i<10;i++)
  {
    pinMode(i,OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (!endTime)
  {
      for(int i=0;i<10;i++)
   {
    //显示数字
    for(int j=0;j<input_number[i];j++)
    {
      Serial.println(number[i][j]);
      digitalWrite(number[i][j],HIGH);
    } 
    
    if (i==0 || i==9)
    {
        delay(1000);//9时候停留一秒
    }
    else
    {
      delay(200);
    }
    
    for(int j=0;j<input_number[i];j++)
    {
      Serial.println(number[i][j]);
      digitalWrite(number[i][j],LOW);
    } 
    if(i==9)
    {
      endTime=true;  
    }
   }
  }
  else
  {
    digitalWrite(3,HIGH);
    delay(500);
    digitalWrite(3,LOW);
    delay(500);
  }

 }


