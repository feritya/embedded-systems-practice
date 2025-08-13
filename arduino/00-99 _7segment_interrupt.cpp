const int segmentPins[7] = {8, 9, 3, 4, 5, 6, 7};
const int digitPins[2]   = {12, 13};

const byte rakamlar[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

const int butonPin = 2;
volatile int sayi = 0;
volatile unsigned long sonZaman = 0;

void setup() {
  for (int i = 0; i < 7; i++) pinMode(segmentPins[i], OUTPUT);
  for (int i = 0; i < 2; i++) pinMode(digitPins[i], OUTPUT);

  pinMode(butonPin, INPUT_PULLUP);
  attachInterrupt(0, sayacArttir, FALLING);

}

void loop() {  sayiGoster(sayi); 

}

void sayacArttir() {
  unsigned long simdi = millis();
  if (simdi - sonZaman > 200) { 
    sayi++;
    if (sayi > 99) sayi = 0;
     sayi %= 100;
    sonZaman = simdi;
  }
  }




void sayiGoster(int num) {
  int onlar = num / 10;
  int birler = num % 10;

  digitalWrite(digitPins[1], LOW);
  digitalWrite(digitPins[0], HIGH);
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], rakamlar[onlar][i]);
  }
  
  for (int i = 0; i < 7; i++) digitalWrite(segmentPins[i], LOW);

  digitalWrite(digitPins[0], LOW);
  digitalWrite(digitPins[1], HIGH);
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], rakamlar[birler][i]);
  }

  for (int i = 0; i < 7; i++) digitalWrite(segmentPins[i], LOW);
}

