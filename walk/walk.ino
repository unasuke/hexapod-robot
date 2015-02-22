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

#include <Wire.h>
#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>

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
#define SERVO_L 11

//入力された角度からパルス幅を求める
//input degree to pulse
double degree2Pulse( double degree ){
  double oneDigreePulse = ( SERVO_PULSE_MAX_SEC - SERVO_PULSE_MIN_SEC )
      / SERVO_MAX_DEGREE;
  double pulse = ( degree * oneDigreePulse ) + SERVO_PULSE_MIN_SEC;
  return pulse;
}

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
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setServoPulse(uint8_t n, double pulse) {
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
}

void setup(){

  //Serial out
  Serial.begin(9600);
  Serial.println("Servo Pulse Test");

  //Adafruit Driver Seting
  pwm.begin();
  pwm.setPWMFreq(50);

  //set default position
  for( int i = 0; i < 16; i++ ){
    setServoPulse( i , degree2Pulse(90) );
  }

  int tmp = 120;
  setServoPulse( SERVO_A , degree2Pulse(tmp) );
  setServoPulse( SERVO_C , degree2Pulse(tmp) );
  setServoPulse( SERVO_E , degree2Pulse(tmp) );
  setServoPulse( SERVO_G , degree2Pulse(tmp) );
  setServoPulse( SERVO_I , degree2Pulse(tmp) );
  setServoPulse( SERVO_K , degree2Pulse(tmp) );

}

void loop(){

  double degreetemp;
  double tmp;
  int delaysec = 1000;

  /*degreetemp = degree2Pulse( 90 );
  for( int i = 0; ; i++ ){
    setServoPulse( i , degreetemp );
    if( i > 15 )  i = 0;
  }*/

  //set default position
  /*for( int i = 0; i < 16; i++ ){
    setServoPulse( i , degree2Pulse(90) );
  }*/

  //////////////////////////////////
  //        walking             //
  ////////////////////////////////

  //up front leg
  /*tmp = 60;
  setServoPulse( SERVO_A , degree2Pulse(tmp) );
  setServoPulse( SERVO_K , degree2Pulse(tmp) );
  delay(delaysec);*/
  /*tmp = 120;
  setServoPulse( SERVO_A , degree2Pulse(60) );
  setServoPulse( SERVO_C , degree2Pulse(60) );
  setServoPulse( SERVO_E , degree2Pulse(60) );
  setServoPulse( SERVO_G , degree2Pulse(60) );
  setServoPulse( SERVO_I , degree2Pulse(60) );
  setServoPulse( SERVO_K , degree2Pulse(60) );
  delay(delaysec);*/


  tmp = 120;
  setServoPulse( SERVO_A , degree2Pulse(60) );
  setServoPulse( SERVO_B , degree2Pulse(tmp) );
  delay(100);
  setServoPulse( SERVO_K , degree2Pulse(60) );
  setServoPulse( SERVO_L , degree2Pulse(degreeReverse(tmp)));
  delay(100);
  setServoPulse( SERVO_E , degree2Pulse(60) );
  setServoPulse( SERVO_F , degree2Pulse(tmp) );
  delay(100);
  setServoPulse( SERVO_G , degree2Pulse(60) );
  setServoPulse( SERVO_H , degree2Pulse(degreeReverse(tmp)));
  delay(100);
  setServoPulse( SERVO_C , degree2Pulse(60) );
  setServoPulse( SERVO_D , degree2Pulse(tmp) );
  delay(100);
  setServoPulse( SERVO_I , degree2Pulse(60) );
  setServoPulse( SERVO_J , degree2Pulse(degreeReverse(tmp)));
  delay(100);

  tmp = 90;
  setServoPulse( SERVO_A , degree2Pulse(120) );
  setServoPulse( SERVO_B , degree2Pulse(tmp) );
  delay(100);
  setServoPulse( SERVO_K , degree2Pulse(120) );
  setServoPulse( SERVO_L , degree2Pulse(degreeReverse(tmp)));
  delay(100);
  setServoPulse( SERVO_E , degree2Pulse(120) );
  setServoPulse( SERVO_F , degree2Pulse(tmp) );
  delay(100);
  setServoPulse( SERVO_G , degree2Pulse(120) );
  setServoPulse( SERVO_H , degree2Pulse(degreeReverse(tmp)));
  delay(100);
  setServoPulse( SERVO_C , degree2Pulse(120) );
  setServoPulse( SERVO_D , degree2Pulse(tmp) );
  delay(100);
  setServoPulse( SERVO_I , degree2Pulse(120) );
  setServoPulse( SERVO_J , degree2Pulse(degreeReverse(tmp)));
  delay(100);

  /*//up front leg
  tmp = 60;
  setServoPulse( SERVO_A , degree2Pulse(tmp) );
  setServoPulse( SERVO_G , degree2Pulse(tmp) );
  delay(delaysec);

  //forward front knee
  tmp = 120;
  setServoPulse( SERVO_B , degree2Pulse(tmp) );
  setServoPulse( SERVO_H , degree2Pulse(degreeReverse(tmp)));
  delay(delaysec);

  //down front leg
  tmp = 90;
  setServoPulse( SERVO_A , degree2Pulse(tmp) );
  setServoPulse( SERVO_G , degree2Pulse(tmp) );
  delay(delaysec);

  //up middle leg
  tmp = 60;
  setServoPulse( SERVO_C , degree2Pulse(tmp) );
  setServoPulse( SERVO_I , degree2Pulse(tmp) );
  delay(delaysec);

  //forward middle knee
  tmp = 120;
  setServoPulse( SERVO_D , degree2Pulse(tmp) );
  setServoPulse( SERVO_J , degree2Pulse(degreeReverse(tmp)));
  delay(delaysec);

  //down midle leg
  tmp = 90;
  setServoPulse( SERVO_C , degree2Pulse(tmp) );
  setServoPulse( SERVO_I , degree2Pulse(tmp) );
  delay(delaysec);

  //up back leg
  tmp = 60;
  setServoPulse( SERVO_E , degree2Pulse(tmp) );
  setServoPulse( SERVO_K , degree2Pulse(tmp) );
  delay(delaysec);

  //forward back knee
  tmp = 120;
  setServoPulse( SERVO_F , degree2Pulse(tmp) );
  setServoPulse( SERVO_L , degree2Pulse(degreeReverse(tmp)));
  delay(delaysec);

  //down back leg
  tmp = 90;
  setServoPulse( SERVO_E , degree2Pulse(tmp) );
  setServoPulse( SERVO_K , degree2Pulse(tmp) );
  delay(delaysec);*/


}
