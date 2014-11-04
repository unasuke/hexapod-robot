/***************************************************
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 16 servos, one after the other
  Adafruit 16-channel PWM & Servo driverのサーボモータテスト用コードです。
  16のサーボモータを順次動かします。

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815
  購入ページはこちらです。

  These displays use I2C to communicate, 2 pins are required to
  interface. For Arduino UNOs, thats SCL -> Analog 5, SDA -> Analog 4
  I2C通信で使用します。Arduino UNOではSCLをAnalog 5 pinへ、SDAをAnalog 4 pinへ
  接続してください。

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!
  Adafruitは時間とリソースをこのOpen Sourceなコードに費やしました。
  AdafruitのOpen Sourceなハードウェアを支援するために、我々の製品を
  買ってください！

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
// Adafruit_PWMServoDriverを引数なしで呼び出すと、デフォルトのアドレスである
// 0x40にセットされます。
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
// 異なるアドレスのDrierを使用するときはアドレスを引数にして呼び出してください。
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
// 使用するサーボモータを決定したら、パルス幅のMAXとMINを変更する必要が
// あるかもしれません。サーボモータの可動範囲を超えない、限界まで大きな(小さな)
// 値に設定します。この作業には微調整が必要になるかもしれません。

// パルス幅最小値(4096以内)
#define SERVOMIN  0 // this is the 'minimum' pulse length count (out of 4096)

// パルス幅最大値(4096以内)
#define SERVOMAX  4096 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
// サーボモータ数のカウント用変数
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  pwm.begin();

  pwm.setPWMFreq(50);  // Analog servos run at ~60 Hz updates
  // PWM信号の周波数を設定
}

// you can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. its not precise!
// 秒単位でパルス幅を設定する場合にはこの関数を使用します。
// 例 setServoPulse(0, 0.001) ← パルス幅1ミリ秒(正確ではありません)
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

void loop() {
  // Drive each servo one at a time
  // 各サーボモータを1つずつ動かす
  Serial.println(servonum);
  /*for( int i = 0; i < 10; i++ ){
    for( servonum = 0; servonum < 16; servonum++ ){
    setServoPulse( servonum , 0.0010 );
    }
    delay(1000);

    for( servonum = 0; servonum < 16; servonum++ ){
    setServoPulse( servonum , 0.0015 );
    }
    delay(1000);

    for( servonum = 0; servonum < 16; servonum++ ){
    setServoPulse( servonum , 0.0020 );
    }
    delay(1000);
  }*/
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    Serial.println(pulselen);
    for( int i = 0; i < 10; i++ ){
      //pwm.setPWM(servonum, 0, pulselen);
      setServoPulse( servonum , 0.771 );
      delay(500);
    }
    for( int i = 0; i < 10; i++ ){
      //pwm.setPWM(servonum, 0, pulselen);
      setServoPulse( servonum , 2.193 );
      delay(500);
    }
  }
  delay(500);
  /*for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(servonum, 0, pulselen);
  }
  delay(500);

  servonum ++;*/
  if (servonum > 15) servonum = 0;
}
