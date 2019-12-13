void Scroll(int8_t NumTab[],int sizes, int timez){
  disp.clearDisplay();
  uint8_t ListDisp[4];
  unsigned char  i = 0;
  unsigned char count = 0;
  for(int n = 0;n<timez;n++){
    i = count;
    count++;
    if(count == sizes){
      count = 0;  
    }
  
  for(unsigned char BitSelect = 0; BitSelect < 4; BitSelect++)
    {
      ListDisp[BitSelect] = NumTab[i];
      i++;
      if(i == sizes )
      {
        i = 0;
      }
    }
    disp.display( (uint8_t)0, ListDisp[0]);
    disp.display( (uint8_t)1, ListDisp[1]);
    disp.display( (uint8_t)2, ListDisp[2]);
    disp.display( (uint8_t)3, ListDisp[3]);
    delay(300);
  }
}

void Still(int8_t NumTab[],int sizes){
  disp.clearDisplay();
  uint8_t ListDisp[4];
  unsigned char  i = 0;
  for(unsigned char BitSelect = 0; BitSelect < 4; BitSelect++)
    {
      ListDisp[BitSelect] = NumTab[i];
      i++;
      if(i == sizes )
      {
        i = 0;
      }
    }
    
   disp.display( (uint8_t)0, ListDisp[0]);
    disp.display( (uint8_t)1, ListDisp[1]);
    disp.display( (uint8_t)2, ListDisp[2]);
    disp.display( (uint8_t)3, ListDisp[3]);
    delay(500);
}
