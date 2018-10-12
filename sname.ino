#include <SoftwareSerial.h>
//pin location
int mo1 = 7;
int mo2 = 2;
int mo3 = 3;
int mo4 = 4;
int mo5 = 5; //pwm a
int mo6 = 6; //pwm b
int trig = 8;
int echo = 9;
int led = 12;
int ledhead = 14;
const int voca = 13; //蜂鳴器
int mo5v = 130, mo6v = 100;
char K;
float cm;
SoftwareSerial BTSerial(0, 1);
char val;
void setup() {
  // Initalize
  Serial.begin(9600);
  pinMode(mo1, OUTPUT);
  pinMode(mo2, OUTPUT);
  pinMode(mo3, OUTPUT);
  pinMode(mo4, OUTPUT);
  pinMode(mo5, OUTPUT);
  pinMode(mo6, OUTPUT);
  pinMode(voca, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(ledhead, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(ledhead, HIGH);
  BTSerial.begin(9600);
  /*  tone(voca, 262, 500);
    noTone(100);
    tone(voca, 294, 500);
    noTone(100);
    tone(voca, 330, 500);
    noTone(100);
    tone(voca, 392, 500);
    noTone(100);*/
}

void loop() {
  //This is a loop~
  if (BTSerial.available()) {
    K = BTSerial.read();
    Serial.print(K);
  }
  digitalWrite(trig, LOW);
  delay(5);
  digitalWrite(trig, HIGH);
  digitalWrite(trig, LOW);
  cm = pulseIn(echo, HIGH) / 58.0;
  delay(5);
  Serial.println(cm);
  if (K == '1') {  //前進
    digitalWrite(mo1, LOW);
    digitalWrite(mo2, HIGH);
    digitalWrite(mo3, HIGH);
    digitalWrite(mo4, LOW);
    analogWrite(mo5, mo5v);
    analogWrite(mo6, mo6v);

  }

  if (K == '2') {  //左轉
    digitalWrite(mo1, LOW);
    digitalWrite(mo2, HIGH);
    digitalWrite(mo3, HIGH);
    digitalWrite(mo4, LOW);
    analogWrite(mo5, 140);
    analogWrite(mo6, 70);

  }

  if (K == '3') { //右轉
    digitalWrite(mo1, LOW);
    digitalWrite(mo2, HIGH);
    digitalWrite(mo3, HIGH);
    digitalWrite(mo4, LOW);
    analogWrite(mo5, 70);
    analogWrite(mo6, 140);

  }
  if (K == '4') { //後退
    digitalWrite(mo1, HIGH);
    digitalWrite(mo2, LOW);
    digitalWrite(mo3, LOW);
    digitalWrite(mo4, HIGH);
    analogWrite(mo5, mo5v);
    analogWrite(mo6, mo6v);

  }
  if (K == '5') { //空檔
    digitalWrite(mo1, HIGH);
    digitalWrite(mo2, LOW);
    digitalWrite(mo3, HIGH);
    digitalWrite(mo4, LOW);
    analogWrite(mo5, 0);
    analogWrite(mo6, 0);

  }
  if (K == '6') { //煞車
    digitalWrite(mo1, HIGH);
    digitalWrite(mo2, HIGH);
    digitalWrite(mo3, HIGH);
    digitalWrite(mo4, HIGH);
    analogWrite(mo5, 255);
    analogWrite(mo6, 255);

  }
  if (K == '8') {  //加速前進
    digitalWrite(mo1, LOW);
    digitalWrite(mo2, HIGH);
    digitalWrite(mo3, HIGH);
    digitalWrite(mo4, LOW);
    analogWrite(mo5, 255);
    analogWrite(mo6, 255);

  }
  if (K == '9') {
    tone(voca, 262, 500); //Do
    noTone(100);
    tone(voca, 294, 500); //Re
    noTone(100);
    tone(voca, 330, 500); //Mi
    noTone(100);
    tone(voca, 392, 500); //Sol
    noTone(100);

  }
  if ((cm <= 20.0) && (cm != 0.0)) {
    tone(voca, 700, 200);
    cm = 0.0;
  }
  if ((cm <= 15.0) && (cm != 0.0)) {
    tone(voca, 700, cm * 20);
  }

}
