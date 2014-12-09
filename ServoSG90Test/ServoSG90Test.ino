#include <Wire.h>
#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>

//パルス幅の範囲(単位:sec)
//0.771msのpulseで0°
//2.193msのpulseで130°[要検証]
#define SERVO_PULSE_MIN_SEC 0.771
#define SERVO_PULSE_MAX_SEC 2.193

//パルス幅の範囲(0から4096まで)
#define SERVO_MIN 0
#define SERVO_MAX 4096

//入力された角度からパルス幅を求める
double degree2Pulse( double degree ){
  double oneDigreePulse = ( SERVO_PULSE_MAX_SEC - SERVO_PULSE_MIN_SEC ) / 130;
  double pulse = ( degree * oneDigreePulse ) + SERVO_PULSE_MIN_SEC;
  return pulse;
}

//Adafruitドライバの初期化
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setServoPulse(uint8_t n, double pulse) {
  double pulselength;

  pulselength = 1000000;   // 1,000,000 us per second
  // 1秒は1000000マイクロ秒
  pulselength /= 50;   // 60 Hz
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

}

void loop(){
  for( int i = 0; i < 16; i++ ){
    setServoPulse( i , degree2Pulse( 0 /*i < 90?0:90*/ ) );
  }
  for( int i = 0; i <= 120; i+=30){
    for( int j = 0; j < 16; j++ ){
      setServoPulse( j , degree2Pulse( 0 /*i < 90?0:90*/ ) );
    }
    //delay(1);
    if( i > 119.0 ) i = 0;
    else;
  }
}
