int redPin = 3;
int greenPin = 5;
int bluePin = 6;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<256;i++)
  {
    analogWrite(redPin,i);
     analogWrite(greenPin,i);
      analogWrite(bluePin,i);
      int dy=map(i,0,255,0,25);
      delay(25-dy);
      Serial.println(i);
  }
  delay(1000);
    for(int i=255;i>0;i--)
  {
    analogWrite(redPin,i);
     analogWrite(greenPin,i);
      analogWrite(bluePin,i);
      int dy=map(i,0,255,0,25);
      delay(25-dy);
  }
  delay(500);

}
