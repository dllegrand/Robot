import controlP5.*;
import processing.serial.*;

Serial port;

ControlP5 cp5;

void setup(){
  size(400,400); 
  
  cp5 = new ControlP5(this);
  
  printArray(Serial.list());
  port = new Serial(this,"COM3",115200);
  
  cp5.addButton("Forward")
    .setPosition(100,80)
    .setImages(loadImage("Arrow-Up.png"),loadImage("Arrow-Up.png"),loadImage("Arrow-Up.png"))
    .updateSize()
    ;
  
  cp5.addButton("Reverse")
    .setPosition(100,180)
    .setImages(loadImage("Arrow-Down.png"),loadImage("Arrow-Down.png"),loadImage("Arrow-Down.png"))
    .updateSize()
    ;
  
  cp5.addButton("Right")
    .setPosition(150,130)
    .setImages(loadImage("Arrow-Right.png"),loadImage("Arrow-Right.png"),loadImage("Arrow-Right.png"))
    .updateSize()
    ;
   
  cp5.addButton("Left")
    .setPosition(50,130)
    .setImages(loadImage("Arrow-Left2.png"),loadImage("Arrow-Left2.png"),loadImage("Arrow-Left2.png"))
    .updateSize()
    ;
  cp5.addButton("Stopped")
    .setPosition(250,130)
    .setImages(loadImage("stop.png"),loadImage("stop.png"),loadImage("stop.png"))
    .updateSize()
    ;
  cp5.addButton("Increase")
    .setPosition(250,60)
    .setImages(loadImage("acc.png"),loadImage("acc.png"),loadImage("acc.png"))
    .updateSize()
    ;
  cp5.addButton("Decrease")
    .setPosition(250,200)
    .setImages(loadImage("dec.png"),loadImage("dec.png"),loadImage("dec.png"))
    .updateSize()
    ;
  cp5.addButton("AI")
    .setPosition(10,310)
    .setImages(loadImage("AI2.png"),loadImage("brain.png"),loadImage("brain.png"))
    .updateSize()
    ;
  cp5.addButton("Temp")
    .setPosition(80,310)
    .setImages(loadImage("snowflake.png"),loadImage("hands.png"),loadImage("hands.png"))
    .updateSize()
    ;
  cp5.addButton("Dance")
    .setPosition(150,310)
    .setImages(loadImage("confetti.png"),loadImage("dance.png"),loadImage("dance.png"))
    .updateSize()
    ;
  cp5.addButton("Bees")
    .setPosition(230,310)
    .setImages(loadImage("bee.png"),loadImage("running.png"),loadImage("bee.png"))
    .updateSize()
    ;

cp5.addButton("Bed")
    .setPosition(300,310)
    .setImages(loadImage("bed2.png"),loadImage("bed.png"),loadImage("bed.png"))
    .updateSize()
    ;
}

void draw(){
  background(150,150,150);
  fill(0,20,150);
  textSize(26); 
  text("Milton Control Board",75,30);
}


void Forward(){
  port.write('u');
}
void Reverse(){
  port.write('d');
}
void Left(){
  port.write('l');
}
void Right(){
  port.write('r');
}
void Stopped(){
  port.write('s');
}
void Increase(){
  port.write('n');
}
void Decrease(){
  port.write('c');
}
void AI(){
  port.write('a');
}
void Dance(){
  port.write('p');
}
void Temp(){
  port.write('t');
}
void Bees(){
  port.write('b');
}
void Bed(){
  port.write('e');
}
