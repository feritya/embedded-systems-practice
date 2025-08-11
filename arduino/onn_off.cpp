//3. ve 4.sor 

const int ledPins1[8] = {2,3,4,5,6,7,8,9};
const int ledPins[8] = {9,8,7,6,5,4,3,2};
const int button1 = 8;


void setup() {
  for (int i = 0; i <8; i++) {
    pinMode(ledPins[i],OUTPUT); 
  }
}

void loop() {
  for (int i=0; i<8;i++) {
    if (digitalRead(button1) == LOW)
    digitalWrite(ledPins[i],HIGH);
    delay(500);   
    digitalWrite(ledPins[i],LOW);
  }
}
