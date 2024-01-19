int numbers[10][7]={{1, 1, 1, 1, 1, 1, 0}, 
                    {0, 1, 1, 0, 0, 0, 0}, 
                    {1, 1, 0, 1, 1, 0, 1}, 
                    {1, 1, 1, 1, 0, 0, 1}, 
                    {0, 1, 1, 0, 0, 1, 1}, 
                    {1, 0, 1, 1, 0, 1, 1}, 
                    {1, 0, 1, 1, 1, 1, 1}, 
                    {1, 1, 1, 0, 0, 0, 0},
                    {1, 1, 1, 1, 1, 1, 1},
                    {1, 1, 1, 0, 1, 1, 1}};//0-9
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
  Serial.begin(9600);
 for (int i=2;i<10;i++)
  {
    //Serial.println(i);
    pinMode(i,OUTPUT);
    
  }
   
}

void loop() {
  // put your main code here, to run repeatedly:
  num(numbers[0]);
  //digitalWrite(10,HIGH);
  //digitalWrite(9,HIGH);
  delay(1000);

}
