int ledPin = 5; //LED
const int buttonPin = 2; 
int buttonState; //按钮状态
int ledValue = 255;
const int add=51;

unsigned long lastDebounceTime = 0;  //按下时间
unsigned long TimeTick = 0;//时长 
unsigned long debounceDelay=3000;

bool buttonPress = false; // 记录按钮是否已经被按下
bool on=false;// 记录LED灯的状态
bool record=false;
bool lit_add=false;//灯是否变化

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);//端口检测

}
void adding()
{
    if (lit_add==false)
    {
      if (ledValue -add<0)
      { 
        //Serial.println(1111);//检测
        ledValue =204;
        lit_add=true;  
      }
      else{
        //Serial.println(2222);//检测
        ledValue-=add;
        lit_add=true; 
      }
     
    }
    //Serial.println(ledValue);  
}

void loop() 
{
  buttonState=digitalRead(buttonPin);
  if(buttonState==LOW)//一次按下开关
  {

    if (buttonPress==false)//未按下状态
    {
      lastDebounceTime=millis();
    }
    buttonPress=true;//已经记录开始时间

    if (record==false && !on)
    {
      on=true;
      ledValue=102;
      record=true;
      lit_add=true;
      Serial.println(2222);
    }
    delay(100);

    TimeTick=millis()-lastDebounceTime;
    //Serial.println(TimeTick);
    if (TimeTick>debounceDelay && record==false)//长按3s
    {
      //Serial.println(on);
      if (on==true)
      {
        ledValue=255;//关灯
        on=false;
      }
      record=true;
    }
  }

  
  if (buttonState==HIGH && on == false)//关灯状态
  {
    ledValue=255;
    buttonPress = false; 
    record=false;
    lit_add=false;
  }
  if (buttonState==HIGH && on == true)//一次开灯后
  {
    if(buttonPress)
    {
      adding();
    }
    
    buttonPress = false; 
    record=false;
    lit_add=false;
    
  }
  
  analogWrite(ledPin,ledValue);
//Serial.println(buttonPress);
 
}


