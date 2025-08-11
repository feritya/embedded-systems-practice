// 6. 2 tane fonksiyon yazınız
// Arduino'yu şu şekilde modelleyin
// 2-6 arası A portu
// 6-10 arası B portu
// 10-14 arası C portu
// 14-18 arası D portu şeklinde modelle

// yazacağınız fonksiyon ,tüm portu ya giriş ya da çıkış yapsın

// 2. fonksiyon komple o portun pinlerini ON ya da OFF yapsın.

void doIO(int status,int ledpins[]) {
  if (status ==0){
    for (int i = 0; i <4; i++) {
    pinMode(ledpins[i],OUTPUT); 
    }
  }
  if (status ==1){
    for (int i = 0; i <4; i++) {
    pinMode(ledpins[i],INPUT); 
    }
    
  }


}

void doOnOff(int status,int ledpins[]) {
  if (status==0){
    for (int i = 0; i <4; i++) {
    digitalWrite(ledpins[i], LOW);  
    }
  }
  if (status ==1){
    for (int i = 0; i <4; i++) {
    digitalWrite(ledpins[i], HIGH);  
    }
    
  }

}

const int A[4] = {2,3,4,5};
const int B[4] = {6,7,8,9};
const int C[4] = {10,11,12,13};
const int D[4] = {14,15,16,17};



void setup() {

  doIO(1, A);       
  doIO(1, B);       
  doIO(1, C);       
  doIO(0, D);       


}

void loop() {



  doOnOff(0, D);
  delay(500);
  doOnOff(1, D);
  delay(500);


}
