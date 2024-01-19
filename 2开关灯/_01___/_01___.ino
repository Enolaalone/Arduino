int sensorPin = A0;    // 传感器检测A0
int ledPin = 5;      //LED
const int buttonPin = 2; 
int buttonState; 
int sensorValue = 0; //读取中间阻值
int button = 0; 

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {

  sensorValue = analogRead(sensorPin);//读取中间阻值
  int ledValue = map(sensorValue,0,1023,0,255);//映射
  analogWrite(ledPin, ledValue);
  }


 
