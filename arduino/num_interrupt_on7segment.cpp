/*
7 segment displayde 0-9 rakamlarını göstermek için interrupt kullanarak
butona basıldıkça sayıyı arttırın.
*/
const int segmentPins[7] = {8, 9, 3, 4, 5, 6, 7};

const byte rakamlar[10][7] = {
  {1,1,1,1,1,1,0}, 
  {0,1,1,0,0,0,0}, 
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1}, 
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1}, 
  {1,0,1,1,1,1,1}, 
  {1,1,1,0,0,0,0}, 
  {1,1,1,1,1,1,1}, 
  {1,1,1,1,0,1,1}  
};


const int butonPin = 2; 
volatile int sayi = 0;  
volatile unsigned long sonZaman = 0; 

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  
  pinMode(butonPin, INPUT_PULLUP);

  attachInterrupt(0, sayacArttir, FALLING);
  
  sayiGoster(sayi);
}

void loop() {
  // Sürekli olarak mevcut sayıyı göster
  sayiGoster(sayi);
}

void sayacArttir() {
  unsigned long simdi = millis();
  if (simdi - sonZaman > 300) { 
    sayi++;
    if (sayi > 9) sayi = 0;
    sonZaman = simdi;
  }
}

void sayiGoster(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], rakamlar[num][i]);
  }
}