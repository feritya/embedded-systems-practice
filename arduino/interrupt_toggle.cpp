const int butonPin = 2;   
const int ledPin = 13;   
volatile bool ledDurum = false; 
volatile unsigned long sonZaman = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(butonPin, INPUT_PULLUP); 

  attachInterrupt(digitalPinToInterrupt(butonPin), toggleLED, FALLING);
}

void loop() {
}

void toggleLED() {
  unsigned long simdi = millis();
  
  if (simdi - sonZaman > 500) {
    ledDurum = !ledDurum;             
    digitalWrite(ledPin, ledDurum);   
    sonZaman = simdi;
  }
}
