#include "MeOrion.h"
#include <Wire.h>
#include <SoftwareSerial.h>

MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
uint8_t motorSpeed=100;

MeUltrasonicSensor ultraSensor(PORT_8);


void setup()
{
  //Serial.begin(9600);
}

void loop()
{
  /*
  Serial.print("Distance: ");
  Serial.print(ultraSensor.distanceCm() );
  Serial.println(" cm");
  delay(100);
  */
  double distance = ultraSensor.distanceCm();
  if (distance < 25) 
  {
    motor1.run(motorSpeed*2);
    motor2.run(motorSpeed*2);
  }
  else 
  {
    motor1.run(-motorSpeed);
    motor2.run(motorSpeed);
  }
 
  motor1.stop();
  motor2.stop();
  delay(2000);
  
}
