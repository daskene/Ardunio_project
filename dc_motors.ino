#include <Servo.h>
#define SERVO_PIN 9
#define GROUND_JOY_PIN A3            //joystick ground pin will connect to Arduino analog pin A3
#define VOUT_JOY_PIN A2              //joystick +5 V pin will connect to Arduino analog pin A2
#define XJOY_PIN A1//X axis reading from joystick will go into analog pin A1
#define YJOY_PIN A0
#include <AFMotor.h> 
AF_DCMotor motor(1, MOTOR12_64KHZ);
int angle = 180;
int Jval;
int Ival;
Servo myservo ;

void setup() {
 Serial.begin(9600);
 pinMode(VOUT_JOY_PIN, OUTPUT) ;    //pin A3 shall be used as output
 pinMode(GROUND_JOY_PIN, OUTPUT) ;  //pin A2 shall be used as output
 digitalWrite(VOUT_JOY_PIN, HIGH) ; //set pin A3 to high (+5V)
 digitalWrite(GROUND_JOY_PIN,LOW) ; //set pin A3 to low (ground)
 pinMode(LED_BUILTIN, OUTPUT);
 myservo.attach(9);  
 motor.setSpeed(255);

}

void loop() {

Jval=analogRead(XJOY_PIN);
Serial.println(Jval);
Ival=analogRead(YJOY_PIN);
Serial.println(Ival);

 
  

  if (Jval > 1015){
    motor.setSpeed(255);
    motor.run(FORWARD);
    }
    else if(Jval < 1015 && Jval > 600){
    motor.setSpeed(100);
    motor.run(FORWARD);
    }
    else if(Jval < 6){
    motor.setSpeed(255);
    motor.run(BACKWARD);
    digitalWrite(LED_BUILTIN, HIGH);
    }
    else if(Jval > 6 && Jval < 400){
      motor.setSpeed(100);
      motor.run(BACKWARD);
      digitalWrite(LED_BUILTIN, HIGH);
      }
    else{
      motor.run(RELEASE);
      digitalWrite(LED_BUILTIN, LOW);
    }

 delay(25);
int angle = map(analogRead(YJOY_PIN), 512,1023,0,220);
myservo.write(angle);



 if (Ival < 400 && Jval > 400 && Jval < 600){ 
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
 }
}
