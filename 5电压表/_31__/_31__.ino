float V=0;
float sensorValue=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(A0);
//  Serial.println(sensorValue);
  V=5*sensorValue/1023;
  Serial.println(V);
}
