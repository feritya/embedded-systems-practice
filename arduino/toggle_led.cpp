

const int ledPin = 9;  
bool ledDurumu = false; 

void setup() {
  pinMode(ledPin, OUTPUT);   
  digitalWrite(ledPin, HIGH); 
  ledDurumu = true;
}

void loop() {
 
  ledDurumu = !ledDurumu;
  digitalWrite(ledPin, ledDurumu); 
  delay(1000); 
}
