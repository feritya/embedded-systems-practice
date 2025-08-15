/*
vNon-blocking mode
Bu kütüphaneyi kullanarak 1500 ms'de ledi toggle yapan kodu kullanınız.
(Tek timer)
*/


#include <arduino-timer.h>

auto timer1 = timer_create_default();
const int ledPin = 13;
volatile bool ledState = false;


void setup() {
  pinMode(ledPin, OUTPUT);
  timer1.every(1500, toggleLED);
}

void loop() {
  timer1.tick(); 
}

bool toggleLED() {
  ledState = !ledState;
  digitalWrite(ledPin, ledState);
  return 1;
  }
