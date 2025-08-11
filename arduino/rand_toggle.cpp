//5. rastgele olarak 8'ledi toggle yapan kod yazınız.
//500ms aralıklarla
const int ledPins[8] = {2,3,4,5,6,7,8,9};
bool ledStatus[8] = {false}; 
void setup() {
  for (int i = 0; i <8; i++) {
    pinMode(ledPins[i],OUTPUT); 
    digitalWrite(ledPins[i], LOW);  
     }
}

void loop() {
    int randompin=random(0,8);
    ledStatus[randompin]=!ledStatus[randompin];
    digitalWrite(ledPins[randompin],ledStatus[randompin]);
      delay(250);

}
