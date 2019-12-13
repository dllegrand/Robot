void TimingISR()
{
  second++;
  if(second == 60)
  {
    minute++;
    if(minute == 60)
    {
      hour++;
      if(hour == 24)
      {
        hour = 0;
      }
      minute = 0;
    }
    second = 0;
  }
}

void TimeUpdate(void)
{
  TimeDisp[0] = minute / 10;
  TimeDisp[1] = minute % 10;
  TimeDisp[2] = second / 10;
  TimeDisp[3] = second % 10;
}
void Light(){
  int light = 0;
  long lastTime = 0;
  light = lightSensor.read();
  if (light < 50){
    stopped();
      if(millis() - lastTime >= 1000)
      {
        
        TimingISR();

        TimeUpdate();
        disp.display(TimeDisp);
        lastTime = millis();
        delay(1000);
        
      }
   }
   else {
    second = 0;
    minute = 0;
    hour = 0;
    disp.clearDisplay();
   }
}
