#include <Servo.h>

#define led1GND 2
#define led1VCC 3
#define led2GND 4
#define led2VCC 5
#define ledPWM 6
#define led3GND 7
#define led3VCC 8
#define botao 10

int lerBotao = 0;
int analogico0 = 0;
int analogico1 = 1;
int analogico2 = 2;
int analogico3 = 3;
int posServo = 0;
int subindo = 1;
int valorPWM = 0;

Servo meuServo;

void setup() {
  meuServo.attach(9);
  Serial.begin(9600);
  pinMode(ledPWM, OUTPUT);
  pinMode(led1VCC, OUTPUT);
  pinMode(led1GND, OUTPUT);
  pinMode(led2VCC, OUTPUT);
  pinMode(led2GND, OUTPUT);
  pinMode(led3VCC, OUTPUT);
  pinMode(led3GND, OUTPUT);
  pinMode(botao, INPUT);
}

void loop() {

 
 lerBotao = digitalRead(botao);

  if (lerBotao == HIGH) {
    digitalWrite(led1VCC, HIGH);
    digitalWrite(led1GND, LOW);
    digitalWrite(led2VCC, HIGH);
    digitalWrite(led2GND, HIGH);
    digitalWrite(led3VCC, HIGH);
    digitalWrite(led3GND, LOW);
        
  } else {
    digitalWrite(led1VCC, HIGH);
    digitalWrite(led1GND, HIGH);
    digitalWrite(led2VCC, HIGH);
    digitalWrite(led2GND, LOW);
    digitalWrite(led3VCC, HIGH);
    digitalWrite(led3GND, HIGH);
  }
  
 delay(300);
 analogico0 = analogRead(A0);
 analogico1 = analogRead(A1);
 analogico2 = analogRead(A2);
 analogico3 = analogRead(A3);
 
 Serial.print("A0= ");
 Serial.println(analogico0);
 Serial.print("A1= ");
 Serial.println(analogico1);
 Serial.print("A2= ");
 Serial.println(analogico2);
 Serial.print("A3= ");
 Serial.println(analogico3);

  if (subindo == 1){
    posServo = posServo +18;
    meuServo.write(posServo);
    if (posServo >= 180){
     subindo = 0; 
    }
    delay(100);
   }
  if (subindo == 0){
    posServo = posServo -18;
    meuServo.write(posServo);
      if (posServo <= 0){
     subindo = 1; 
    }
    delay(100);
    } 
   
  
  valorPWM = map(posServo, 0, 180, 0, 175);
  // change the analog out value:
  analogWrite(ledPWM, valorPWM);
  }
