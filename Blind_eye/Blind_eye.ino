#include <SoftwareSerial.h>
#define trigPin1 3
#define echoPin1 2
#define trigPin2 4
#define echoPin2 5
#define buzz1 10
#define buzz2 6
SoftwareSerial BTserial(11,12); // rx tx
long duration, distance, RightSensor,BackSensor,FrontSensor,LeftSensor;

void setup()
{
Serial.begin (9600);
BTserial.begin(9600); 
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT); 
pinMode(echoPin2, INPUT);
pinMode(buzz1,OUTPUT);
pinMode(buzz2,OUTPUT);
}

void loop() {
SonarSensor(trigPin1, echoPin1);/
RightSensor = distance;
SonarSensor(trigPin2, echoPin2);
LeftSensor = distance;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  

Serial.print(LeftSensor);
Serial.print(" - ");
Serial.println(RightSensor);


if( LeftSensor < 100){
  Serial.println("Turn Right");
  BTserial.println("Turn Right");
  digitalWrite(buzz1,HIGH);
  delay(100);
  digitalWrite(buzz1,LOW);
  
}
else if (RightSensor < 100){
  Serial.println("Turn Left");
  BTserial.println("Turn Left");
  digitalWrite(buzz2,HIGH);
  delay(100);
  digitalWrite(buzz2,LOW);
}
else{
  Serial.println("Go straight");
  BTserial.println("Go straight");
  delay(100);
}
}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

}
