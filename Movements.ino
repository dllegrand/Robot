void forward(){
  motor1.run(RightSpeed);
  motor2.run(-LeftSpeed);
}

void backward(){
  motor1.run(-RightSpeed);
  motor2.run(LeftSpeed);
}

void brake(){
  RightSpeed = RightSpeed -10;
  LeftSpeed = LeftSpeed -10;
}

void accelerate(){
  RightSpeed = RightSpeed +10;
  LeftSpeed = LeftSpeed +10;
}

void stopped(){
  motor1.stop();
  motor2.stop();
}

void turnright(){
  motor1.run(RightSpeed/2);
  motor2.run(-LeftSpeed*2);
  delay(500);
  motor1.stop();
  motor2.stop();
}

void turnleft(){
  motor1.run(RightSpeed*2);
  motor2.run(-LeftSpeed/2);
  delay(500);
  motor1.stop();
  motor2.stop();
}
