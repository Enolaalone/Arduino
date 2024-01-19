int BlinkTimes=0;
int ledPin=13;
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    //如果串口有可用的数据
   if (Serial.available() > 0) {
    //读取一个整数
    BlinkTimes = Serial.parseInt();//串口读取整数
    
    //控制LED的闪烁
    for(int i=0;i<BlinkTimes;i++)
    {
      digitalWrite(ledPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
      delay(500);
    }
  }
  digitalWrite(ledPin, HIGH);
}
