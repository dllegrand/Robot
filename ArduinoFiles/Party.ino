void Dance(){
  int8_t Party1[5] = {12,0,0,1,32};
  int8_t Party2[6] = {4,10,10,5,5,32};
  int8_t Party3[9] = {4,14,10,32,11,10,11,4,32};
  int8_t Party4[4] = {15,10,11,32};
  int8_t Party5[4] = {4,10,4,32}; 
  
  motor1.run(RightSpeed); /* value: between -255 and 255. */
  motor2.run(-LeftSpeed); /* value: between -255 and 255. */
  Scroll(Party1,5,3);
  motor1.run(-RightSpeed); /* value: between -255 and 255. */
  motor2.run(LeftSpeed); /* value: between -255 and 255. */
  Scroll(Party2,6,4);
  motor1.run(RightSpeed*3);
  motor2.run(-LeftSpeed/3);
  Scroll(Party3,9,6);
  motor1.run(-RightSpeed/3);
  motor2.run(LeftSpeed*3);
  Scroll(Party4,4,4);
  motor1.run(-RightSpeed*3);
  motor2.run(LeftSpeed/3);
  Scroll(Party5,4,8);
}
