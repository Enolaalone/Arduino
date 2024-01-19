int redPin = 3;//510欧
int greenPin = 5;//200欧
int bluePin = 6;//1000欧

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // 红色到绿色
  for (int i = 0; i <= 255; i++) {
    analogWrite(redPin, 255 - i);
    analogWrite(greenPin, i);
    delay(30);
  }

  // 绿色到蓝色
  for (int i = 0; i <= 255; i++) {
    analogWrite(greenPin, 255 - i);
    analogWrite(bluePin, i);
    delay(35);
  }

  // 蓝色到红色
  for (int i = 0; i <= 255; i++) {
    analogWrite(bluePin, 255 - i);
    analogWrite(redPin, i);
    delay(30);
  }
}


