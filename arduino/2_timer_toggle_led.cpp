/*
Soru2: 2 farklı timer kullanarak birtanesi led1 300 ms aralıklarla yaksın
700 ms aralıklarla yaksın

*/

#include <arduino-timer.h>

auto timer1 = timer_create_default();
auto timer2 = timer_create_default();

const int ledPin = 13;
const int ledPin2 = 12;

volatile bool ledState = false;
volatile bool ledState2 = false;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  timer1.every(300, toggleLED);
  timer2.every(700, toggleLED2);
}

void loop() {
  timer1.tick(); 
  timer2.tick(); 
}
bool toggleLED() {
  ledState = !ledState;
  digitalWrite(ledPin, ledState);
    return !0;

}

bool toggleLED2() {
  ledState2 = !ledState2;
  digitalWrite(ledPin2, ledState2);
  return !0;
}