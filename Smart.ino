void AI(int distance,int distance2){
  Light();
  if (distance2 < 25)
  {
    motor1.run(-RightSpeed);
    motor2.run(LeftSpeed);
    delay(500);
    motor1.run(RightSpeed/2);
    motor2.run(-LeftSpeed*2);
    delay(750);
  }
  else if (distance < 25)
  {
    motor1.run(-RightSpeed);
    motor2.run(LeftSpeed);
    delay(500);
    motor1.run(RightSpeed/2);
    motor2.run(-LeftSpeed*2);
    delay(750);
  }
  else
  {
    motor1.run(RightSpeed);
    motor2.run(-LeftSpeed);
    delay(100);
  }
}
