#include "MeOrion.h"
#include <Wire.h>
#include <SoftwareSerial.h>

/*Sensor definitions*/
Me7SegmentDisplay disp(PORT_3);
MeBluetooth bluetooth(PORT_5);
MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
MeTemperature temp(PORT_6, SLOT1);
MeUltrasonicSensor ultraSensor2(PORT_7);
MeUltrasonicSensor ultraSensor(PORT_4);
MeLightSensor lightSensor(PORT_8);



/*Variable definitions*/
uint8_t TimeDisp[] = { 0x00, 0x00, 0x00, 0x00 };
unsigned char second;
unsigned char minute  = 0;
unsigned char hour  = 12;
uint8_t RightSpeed = 150;
uint8_t LeftSpeed = 150;


/*Function Prototypes*/
void Scroll(int8_t NumTab[], int sizes, int timez);   
void Still(int8_t NumTab[],int sizes);
void AI(int distance, int distance2);


void setup() {  //Runs once at startup
  Serial.begin(115200);
  bluetooth.begin(115200);
  disp.init();
}

void loop() {  //Runs until power-off
 
  if (bluetooth.available()){   //Don't do anything without bluetooth connection
    int8_t Go[4] = {1,32,6,0};      // i Go
    int8_t Back[4] = {11,10,12,12};   //Bacc
    int8_t AIss[4] = {32,10,1,32};    //AI
    
    char cmd = readBT();        //Read Bluetooth input
    
    switch(cmd){
      
      case 'u':              //forward
       Still(Go,4);
       forward(); 
      break;
      
      case 'd':              //backward
       Still(Back,4);
       backward();
       break;
       
      case 'r':              //turnright
      disp.clearDisplay();
       turnright();
      break;
      
      case 'l':              //turnleft
      disp.clearDisplay();
       turnleft();
       break;
       
      case 's':             //stop
      disp.clearDisplay();
       stopped();
       break;
       
      case 'n':             //Speed up
      disp.clearDisplay();
       accelerate();
       break;
       
      case 'c':             //Slow down
      disp.clearDisplay();
       brake();
       break;
       
      case 'a':             //AI
      disp.clearDisplay();
       Still(AIss,4);
       while (char num = 'a'){              //while loop so AI mode is on continously
        int distance;
        int distance2;
        distance = ultraSensor.distanceCm();
        distance2 = ultraSensor2.distanceCm();
        int check;
        AI(distance,distance2);
        num = readBT();
        check = (int)num;                 
        if (num != 'a' && check != -1){     //checking to see if another button has been pressed
          break;
        }
       }
      break;
      
      case 't':               //Im Cold
      disp.clearDisplay();
       while (char num = 't'){
        int check;
        Temp();
        num = readBT();
        check = (int)num;
        if (num != 't' && check != -1){     //checking if another button was pressed
          break;
        }
       }
      break;
      
      case 'p':               //Dance Party
      disp.clearDisplay();
       while (char num = 'p'){
        int check;
        Dance();
        num = readBT();
        check = (int)num;
        if (num != 'p' && check != -1){     //checking if another button was pressed
          break;
        }
       }
      break;
      
      case 'b':              //BEEEEEESSSSSSS
       bees();
      break;
      
      case 'e':                     //BED
       bed();
       while (char num = 'e'){
        int check;
        BedLight();
        num = readBT();
        check = (int)num;
        if (num != 'e' && check != -1){  //checking if another button was pressed
          break;
        }
       }
      break;
    }  
  }
}

/*Bluetooth read function*/
char readBT(){
  char btIn;
  btIn = (char) bluetooth.read();
  return btIn;
}
