#include <Servo.h>

Servo sg90_1;
Servo sg90_2;
int position;
int servopin1 = 9;
int servopin2 = 10;

void setup(){
  pinMode( servopin1 , OUTPUT );
  pinMode( servopin2 , OUTPUT );
  sg90_1.attach( servopin1 );
  sg90_1.write(0);
  sg90_2.attach( servopin2 );
  sg90_2.write(0);
}

void loop(){
  for( position = 0; position <= 180; position++ ){
    //sg90_1.write( position );
    sg90_2.write( position );
    delay(5);
  }
  for( position = 180; position >= 0; position-- ){
    //sg90_1.write( position );
    sg90_2.write( position );
    delay(5);
  }
  /*while(1){
    sg90_1.write( 90 );
    sg90_2.write( 90 );
    delay(50);
  }*/
  delay(1000);
}
