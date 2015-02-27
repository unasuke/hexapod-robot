/*
walk
Hexapod servo placement
    front
  G-H   B-A
     \ /
  I-J---D-C
     / \
  K-L  F-E
    back
*/

//#include <Wire.h>
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

//#include <Adafruit_PWMServoDriver.h>
/*
//パルス幅の範囲(単位:sec) pulse width range
//0.771msのpulseで0°
//2.193msのpulseで130°[要検証]
#define SERVO_PULSE_MIN_SEC 0.771
#define SERVO_PULSE_MAX_SEC 2.193

//サーボの可動範囲 servo moving range
#define SERVO_MIN_DEGREE  0
#define SERVO_MAX_DEGREE  130

//パルス幅の範囲(0から4096まで) pulse range(0 to 4096)
#define SERVO_MIN 0
#define SERVO_MAX 4096

//servo port
#define SERVO_A 0
#define SERVO_B 1
#define SERVO_C 2
#define SERVO_D 3
#define SERVO_E 4
#define SERVO_F 5
#define SERVO_G 6
#define SERVO_H 7
#define SERVO_I 8
#define SERVO_J 9
#define SERVO_K 10
#define SERVO_L 11*/

//入力された角度からパルス幅を求める
//input degree to pulse
/*double degree2Pulse( double degree ){
  double oneDigreePulse = ( SERVO_PULSE_MAX_SEC - SERVO_PULSE_MIN_SEC )
      / SERVO_MAX_DEGREE;
  double pulse = ( degree * oneDigreePulse ) + SERVO_PULSE_MIN_SEC;
  return pulse;
}*/

//入力された角度を反転する
//90°を反転の軸とする
//可動範囲的に、最小値を60、最大値を120とする
//ex.
//60->120
//61->119
//62->118
//...
//118->62
//119->61
//120->60
double degreeReverse( double degree ){
  int minDegree = 60;
  int maxDegree = 120;
  double reverse;

  if( degree < 90 ){
    reverse =  120 - ( degree - 60 );
  }
  else if( degree == 90 ){
    reverse =  degree;
  }
  else if( degree > 90 ){
    reverse = 180 - degree;
  }

  return reverse;
}

//Adafruitドライバの初期化
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

/*void setServoPulse(uint8_t n, double pulse) {
  double pulselength;

  pulselength = 1000000;   // 1,000,000 us per second
  // 1秒は1000000マイクロ秒
  pulselength /= 55;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period");
  pulselength /= 4096;  // 12 bits of resolution
  //分解能は12bit
  Serial.print(pulselength); Serial.println(" us per bit");
  pulse *= 1000;
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}*/

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

  //servoB.write(90);
  servoB.write(120);
  servoD.write(90);
  servoF.write(90);
  servoH.write(90);
  servoJ.write(90);
  servoL.write(120);

  servoA.write(120);
  servoC.write(120);
  servoE.write(120);
  servoG.write(120);
  servoI.write(120);
  servoK.write(120);

  delay(500);
}

void loop(){

  double tmp;
  int delaysec = 300;

  while(true){

    tmp = 60;
    servoC.write(tmp);
    servoI.write(tmp);
    delay(delaysec);

    tmp = 60;
    servoD.write(degreeReverse(tmp+20));
    servoJ.write(tmp);
    delay(delaysec);

    tmp = 120;
    servoC.write(tmp);
    servoI.write(tmp);

    tmp = 90;
    servoA.write(tmp);
    servoE.write(tmp);
    servoG.write(tmp);
    servoK.write(tmp);
    delay(delaysec);

    tmp = 120;
    servoD.write(degreeReverse(tmp-20));
    servoJ.write(tmp);
    delay(delaysec);

    tmp = 120;
    servoA.write(tmp);
    servoE.write(tmp);
    servoG.write(tmp);
    servoK.write(tmp);
    delay(delaysec);
  }

}
