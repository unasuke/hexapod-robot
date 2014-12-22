#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;
Servo servo9;
Servo servo10;
Servo servo11;
Servo servo12;
Servo servo13;
Servo servo14;
Servo servo15;
Servo servo16;

void setup(void){
  servo1.attach(22);
  servo2.attach(24);
  servo3.attach(26);
  servo4.attach(28);
  servo5.attach(30);
  servo6.attach(32);
  servo7.attach(34);
  servo8.attach(36);
  servo9.attach(38);
  servo10.attach(40);
  servo11.attach(42);
  servo12.attach(44);
  servo13.attach(46);
  servo14.attach(48);
  servo15.attach(23);
  servo16.attach(25);
}

void loop(void){
  int i;
  for( i = 0; ;i == 0? i = 90: i = 0  ){
    servo1.write(i);
    servo2.write(i);
    servo3.write(i);
    servo4.write(i);
    servo5.write(i);
    servo6.write(i);
    servo7.write(i);
    servo8.write(i);
    servo9.write(i);
    servo10.write(i);
    servo11.write(i);
    servo12.write(i);
    servo13.write(i);
    servo14.write(i);
    servo15.write(i);
    servo16.write(i);
    delay(1000);
  }

}
