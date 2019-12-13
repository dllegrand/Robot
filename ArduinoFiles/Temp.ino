void Temp(){
  int8_t Cold[4] = {12,0,1,13}; // i Go
  int8_t Yay[4] = {4,10,4,32}; // i Go
  Still(Cold,4);
  int b;
  double currTemp[13];
  double RoomTemp;
  motor1.stop();
  motor2.stop();
  for (b = 0; b < 13; ++b){
    if ( b == 13){
      b == 0;
    }
  currTemp[b] = temp.temperature();
  RoomTemp = currTemp[0];
  if (currTemp[b] > (RoomTemp +0.3)){
     for (int s = 0; s <3; ++s){ 
      motor1.run(RightSpeed*3);
      motor2.run(-LeftSpeed/3);
      Scroll(Yay,4,5);
      motor1.run(RightSpeed/3);
      motor2.run(-LeftSpeed*3);
      Scroll(Yay,4,5);
     }
      delay(500);
      break;
  }
 }
}
