#include <Servo.h>

Servo gripper , wrist , elbow , shoulder , base;

//default position 
double base_angle=90;
double shoulder_angle=90;
double elbow_angle=90;
double wrist_angle=90;


void setup() {
 Serial.begin(9600);
 
  //default digital pin  
  base.attach(12);
  shoulder.attach(11); 
  elbow.attach(10);
  wrist.attach(9);
  gripper.attach(8); 

  base.write(base_angle);
  delay(20);
  shoulder.write(shoulder_angle);
  delay(20);
  elbow.write(elbow_angle);
  delay(20);
  wrist.write(wrist_angle);
  delay(20);

}



String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void loop() {
  
  String computerText = Serial.readStringUntil('@');
  computerText.trim();
  if (computerText.length() == 0) {
    return;
  }
  
  String command = getValue(computerText, ' ',0);

    if (command == "right" || command == "Right" || command == "RIGHT") {
      base.write(base_angle -= 20);
    }
    if (command == "left" || command == "Left" || command == "LEFT") {
     base.write(base_angle += 20);
    }

    if (command == "top" || command == "Top" || command == "TOP") {
      shoulder.write(shoulder_angle -= 20);
    }

   if (command == "bottom" || command == "Bottom" || command == "BOTTOM") {
     shoulder.write(shoulder_angle += 20);
    }
    
  Serial.println(command);
  Serial.println("WORKING");
  delay(1000);

}
