int sensorPin = A0;    // 传感器检测A0
int ledPin = 5;      //LED
const int buttonPin = 2; 
int buttonState; 
int sensorValue = 0; //读取中间阻值

bool button = false; // 记录LED灯的状态
bool buttonPressed = false; // 记录按钮是否已经被按下
//int lastButtonState = LOW; // 记录上一次按钮的状态

void show()
{
  sensorValue = analogRead(sensorPin);//读取中间阻值
  int ledValue = map(sensorValue,0,1023,0,255);//映射相当于除4
  Serial.println(sensorValue);//检测
  analogWrite(ledPin, ledValue);
}


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);//端口检测

}

void loop() {
  buttonState=digitalRead(buttonPin);
  if(buttonState==LOW)//按下开关
  {
    buttonPressed = true;
    show();
    delay(100);
   }
   if (buttonState==HIGH && buttonPressed == true)
  {
    button=!button;//切换
    buttonPressed = false; // 重置按钮按下状态
   }


  if(button==true){
      show();
  }
  else
  {
    //Serial.println(button); //检测
    analogWrite(ledPin, 255);
  }
  

}
