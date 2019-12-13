void bees(){
  int8_t Bee[9] = {11,14,14,14,14,5,17,17,32}; // BEEEES
  motor1.run(-RightSpeed/3);
  motor2.run(LeftSpeed/3);

  Scroll(Bee,9,30);
  motor1.run(RightSpeed/2);
  motor2.run(-LeftSpeed*3);
  Scroll(Bee,9,25);
  motor1.run(RightSpeed);
  motor2.run(-LeftSpeed);
  Scroll(Bee,9,20);
}
