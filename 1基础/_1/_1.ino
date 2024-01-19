
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
 dot();dot();dot();
 dash();dash();dash();
 dot();dot();dot();
 delay(2000);
}

 void dot(){
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100); 
  digitalWrite(13, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(200); 
 }
 
void dash(){
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000); 
  digitalWrite(13, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(250); 
}


 

