void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(5,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=1;i<100;i++)
  {
    digitalWrite(13,HIGH);
    delay(i/10);
    digitalWrite(13,LOW);
    delay(10-i/10);  
  }
  
   for(int i=1;i<100;i++)
  {
    digitalWrite(13,LOW);
    delay(i/10);
    digitalWrite(13,HIGH);
    delay(10-i/10);
    }
    digitalWrite(13,LOW);
    delay(100);

    for(int i=1;i<100;i++)
  {
    digitalWrite(5,HIGH);
    delay(i/10);
    digitalWrite(5,LOW);
    delay(10-i/10);  
  }
  
   for(int i=1;i<100;i++)
  {
    digitalWrite(5,LOW);
    delay(i/10);
    digitalWrite(5,HIGH);
    delay(10-i/10);
    }
    digitalWrite(5,LOW);
    delay(100);

}
