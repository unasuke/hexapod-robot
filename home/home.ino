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
  double tmp = 90;
  servoA.write(tmp);
  servoB.write(tmp);
  servoC.write(tmp);
  servoD.write(tmp);
  servoE.write(tmp);
  servoF.write(tmp);
  servoG.write(tmp);
  servoH.write(tmp);
  servoI.write(tmp);
  servoJ.write(tmp);
  servoK.write(tmp);
  servoL.write(tmp);
}
