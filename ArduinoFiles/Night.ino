void BedLight(){
  int8_t Bye[4] = {11,4,14,17};
  int8_t Yay2[4] = {4,10,4,17};
  int light = 0;
  long lastTime = 0;
  light = lightSensor.read();
  if (light < 50){
    stopped();
    Still(Bye,4);
      }
   else {
    second = 0;
    minute = 0;
    hour = 0;
    Still(Yay2,4);
   }
}

void bed(){
  int8_t Bed[11] = {1,32,6,0,32,2,32,11,14,13,32};
  motor1.run(RightSpeed/3);
  motor2.run(-LeftSpeed/3);
  Scroll(Bed,11,30);
}
