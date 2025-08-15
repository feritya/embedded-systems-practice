/*
Soru3: 3 farklı timer kullanarak birtanesi led1 300 ms aralıklarla yaksın
600 ms aralıklarla yaksın değer led 900 ms aralıklarla yansın

*/

#include <arduino-timer.h>

auto timer1 = timer_create_default();
auto timer2 = timer_create_default();
auto timer3 = timer_create_default();

const int ledPin = 13;
const int ledPin2 = 12;
const int ledPin3 = 11;

volatile bool ledState = false;
volatile bool ledState2 = false;
volatile bool ledState3 = false;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);


  timer1.every(300, toggleLED);
  timer2.every(600, toggleLED2);
  timer3.every(900, toggleLED3);

}

void loop() {
  timer1.tick(); 
  timer2.tick(); 
  timer3.tick(); 

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
bool toggleLED3() {
  ledState3 = !ledState3;
  digitalWrite(ledPin3, ledState3);
  return !0;
}



