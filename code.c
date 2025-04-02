/*
 * Created by Liya G.
 * Created on March 25, 2025
 
 * Uses a sonar with a servo
 */

 # include <Servo.h>


 const int TRIG_PIN = 3;  
 const int ECHO_PIN = 2; 
 const float SPEED_OF_LIGHT = 0.0343;
 const int DISTANCE_TO_MOVE = 50;
 
 Servo servoNumber1;
   
 float duration;
 float distance;
 
 void setup() {
   pinMode(TRIG_PIN, OUTPUT);
   pinMode(ECHO_PIN, INPUT);
   Serial.begin(9600);
   servoNumber1.attach(6); 
   servoNumber1.write(0);
 }
 
 void loop() {
   servoNumber1.write(0);
   digitalWrite(TRIG_PIN, LOW);
   delayMicroseconds(2);
   digitalWrite(TRIG_PIN, HIGH);
   delayMicroseconds(10);
   digitalWrite(TRIG_PIN, LOW);
 
   duration = pulseIn(ECHO_PIN, HIGH);
   distance = (duration*SPEED_OF_LIGHT)/2;
   Serial.print("Distance: ");
   Serial.println(distance);
   delay(100);
   
   if (distance < DISTANCE_TO_MOVE) {
     servoNumber1.write(0);
     delay(1000);
     servoNumber1.write(90);
     delay(1000);
   }
 }