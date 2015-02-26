/*
home
Hexapod servo placement
    front
  G-H   B-A
     \ /
  I-J---D-C
     / \
  K-L  F-E
    back
*/

#include <Servo.h>

Servo servoA;
Servo servoB;
Servo servoC;
Servo servoD;
Servo servoE;
Servo servoF;
Servo servoG;
Servo servoH;
Servo servoI;
Servo servoJ;
Servo servoK;
Servo servoL;

void setup(void){

  servoA.attach(22 , 771 , 2739 );
  servoB.attach(24 , 771 , 2739 );
  servoC.attach(26 , 771 , 2739 );
  servoD.attach(28 , 771 , 2739 );
  servoE.attach(30 , 771 , 2739 );
  servoF.attach(32 , 771 , 2739 );
  servoG.attach(34 , 771 , 2739 );
  servoH.attach(36 , 771 , 2739 );
  servoI.attach(38 , 771 , 2739 );
  servoJ.attach(40 , 771 , 2739 );
  servoK.attach(42 , 771 , 2739 );
  servoL.attach(44 , 771 , 2739 );
}

void loop(){
  servoA.write(90);
  servoB.write(90);
  servoC.write(90);
  servoD.write(90);
  servoE.write(90);
  servoF.write(90);
  servoG.write(90);
  servoH.write(90);
  servoI.write(90);
  servoJ.write(90);
  servoK.write(90);
  servoL.write(90);
}
