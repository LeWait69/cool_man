#include <Servo.h>

Servo ser[5];
int pin[5] = {3, 4, 5, 6, 7};
int bac[5] = {90, 45, 0, 180, 0};

void back(){
  for(int i = 0; i < 5; i++){
    ser[i].write(bac[i]);
  }
}

void setup(){
  Serial.begin(9600);
  for(int i = 0; i < 5; i++){
    ser[i].attach(pin[i]);
  }
  back();
  delay(5000);
}

void wait() {
  while (Serial.read() != 1){
    delay(10);
  }
    return;
}

void first(){
  ser[0].write(45);
  ser[1].write(70);
  delay(1500);
  ser[4].write(90);
  delay(1500);
  ser[3].write(90);
}

void second(){
  ser[0].write(135);
  ser[1].write(70);
  ser[3].write(180);
  delay(1500);
  ser[4].write(0);
  delay(1500);
  ser[3].write(180);
}

void loop() {
  wait();
  first();
  delay(3000);
  second();
  delay(3000);
  back();
  Serial.write(1);
  delay(3000);
  wait();
}
