/*
Task2: 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F karakterlerini 1 saniye aralıklarla
7 segment displayde gösterin.
*/
#define SEGMENT_A 8
#define SEGMENT_B 9
#define SEGMENT_C 3
#define SEGMENT_D 4
#define SEGMENT_E 5
#define SEGMENT_F 6
#define SEGMENT_G 7
#define SEGMENT_DP 10

void setup() {
  pinMode(SEGMENT_A, OUTPUT);
  pinMode(SEGMENT_B, OUTPUT);
  pinMode(SEGMENT_C, OUTPUT);
  pinMode(SEGMENT_D, OUTPUT);
  pinMode(SEGMENT_E, OUTPUT);
  pinMode(SEGMENT_F, OUTPUT);
  pinMode(SEGMENT_G, OUTPUT);
  pinMode(SEGMENT_DP, OUTPUT);
}

void loop() {
  for (int pin0=3;pin0<10;pin0++){
  digitalWrite(pin0,LOW);
  }
  delay(1000);
  for (int pin0=3;pin0<10;pin0++){
  if (pin0==7){
    pin0++;}
  digitalWrite(pin0,HIGH);
  }
    delay(1000);

  for (int pin0=3;pin0<10;pin0++){
  digitalWrite(pin0,LOW);
  }
    delay(1000);


  for (int pin1=3;pin1<10;pin1++){
  if (pin1==9 || pin1==3){
    digitalWrite(pin1,HIGH);
      }
  }
delay(1000);

  for (int pin0=3;pin0<10;pin0++){
  digitalWrite(pin0,LOW);
  }
    delay(1000);


  for (int pin2=3;pin2<10;pin2++){
  if (pin2==SEGMENT_C || pin2==SEGMENT_F){
    pin2++;
      }
          digitalWrite(pin2,HIGH);

  }
delay(1000);

for (int pin0=3;pin0<10;pin0++){
  digitalWrite(pin0,LOW);
  }
    delay(1000);


  for (int pin3=3;pin3<10;pin3++){
  if (pin3==SEGMENT_A || pin3==SEGMENT_B || pin3==SEGMENT_C || pin3==SEGMENT_D || pin3==SEGMENT_G ){
    digitalWrite(pin3,HIGH);
    }

  }
delay(1000);
for (int pin0=3;pin0<10;pin0++){
  digitalWrite(pin0,LOW);
  }
    delay(1000);


  for (int pin3=3;pin3<10;pin3++){
  if (pin3==SEGMENT_F || pin3==SEGMENT_C || pin3==SEGMENT_B || pin3==SEGMENT_G ){
    digitalWrite(pin3,HIGH);
    }

  }
delay(1000);

for (int pin0=3;pin0<10;pin0++){
  digitalWrite(pin0,LOW);
  }
    delay(1000);


  for (int pin3=3;pin3<10;pin3++){
  if (pin3==SEGMENT_F || pin3==SEGMENT_C || pin3==SEGMENT_A || pin3==SEGMENT_G || pin3==SEGMENT_D ){
    digitalWrite(pin3,HIGH);
    }

  }
delay(1000);

for (int pin0=3;pin0<10;pin0++){
  digitalWrite(pin0,LOW);
  }
  delay(1000);


  for (int pin3=3;pin3<10;pin3++){
  if (pin3==SEGMENT_F || pin3==SEGMENT_C || pin3==SEGMENT_A || pin3==SEGMENT_G || pin3==SEGMENT_D || pin3==SEGMENT_E ){
    digitalWrite(pin3,HIGH);
    }

  }
delay(1000);

for (int pin0=3;pin0<10;pin0++){
  digitalWrite(pin0,LOW);
  }
  delay(1000);


  for (int pin3=3;pin3<10;pin3++){
  if (pin3==SEGMENT_C || pin3==SEGMENT_A || pin3==SEGMENT_B){
    digitalWrite(pin3,HIGH);
    }

  }
delay(1000);
for (int pin0=3;pin0<10;pin0++){
  digitalWrite(pin0,LOW);
  }
  delay(1000);
for (int pin0=3;pin0<10;pin0++){
  digitalWrite(pin0,HIGH);
  }
  delay(1000);


for (int pin0=3;pin0<10;pin0++){
  digitalWrite(pin0,LOW);
  }
  delay(1000);


  for (int pin3=3;pin3<10;pin3++){
  if (pin3==SEGMENT_F || pin3==SEGMENT_C || pin3==SEGMENT_A || pin3==SEGMENT_G || pin3==SEGMENT_D || pin3==SEGMENT_B ){
    digitalWrite(pin3,HIGH);
    }

  }
delay(1000);

for (int pin0=3;pin0<10;pin0++){
  digitalWrite(pin0,LOW);
  }
  delay(1000);


  for (int pin3=3;pin3<10;pin3++){
  if (pin3==SEGMENT_F || pin3==SEGMENT_C || pin3==SEGMENT_A || pin3==SEGMENT_G || pin3==SEGMENT_E || pin3==SEGMENT_B ){
    digitalWrite(pin3,HIGH);
    }

  }
delay(1000);

for (int pin0=3;pin0<10;pin0++){
  digitalWrite(pin0,LOW);
  }
  delay(1000);
for (int pin0=3;pin0<10;pin0++){
  digitalWrite(pin0,HIGH);
  }
  delay(1000);


for (int pin0=3;pin0<10;pin0++){
  digitalWrite(pin0,LOW);
  }
  delay(1000);


  for (int pin3=3;pin3<10;pin3++){
  if (pin3==SEGMENT_F || pin3==SEGMENT_A || pin3==SEGMENT_E || pin3==SEGMENT_D ){
    digitalWrite(pin3,HIGH);
    }

  }
delay(1000);


for (int pin0=3;pin0<10;pin0++){
  digitalWrite(pin0,LOW);
  }
  delay(1000);


  for (int pin3=3;pin3<10;pin3++){
  if (pin3==SEGMENT_A || pin3==SEGMENT_B || pin3==SEGMENT_C || pin3==SEGMENT_D || pin3==SEGMENT_E || pin3==SEGMENT_F ){
    digitalWrite(pin3,HIGH);
    }

  }
delay(1000);

for (int pin0=3;pin0<10;pin0++){
  digitalWrite(pin0,LOW);
  }
  delay(1000);


  for (int pin3=3;pin3<10;pin3++){
  if (pin3==SEGMENT_A  || pin3==SEGMENT_D || pin3==SEGMENT_E || pin3==SEGMENT_F || pin3==SEGMENT_G){
    digitalWrite(pin3,HIGH);
    }

  }
delay(1000);

for (int pin0=3;pin0<10;pin0++){
  digitalWrite(pin0,LOW);
  }
  delay(1000);


  for (int pin3=3;pin3<10;pin3++){
  if (pin3==SEGMENT_A  || pin3==SEGMENT_E || pin3==SEGMENT_F || pin3==SEGMENT_G){
    digitalWrite(pin3,HIGH);
    }

  }
delay(1000);

}




