#include <Servo.h>


Servo myservo ;
 
void setup()
{
 Serial.begin(9600);
  pinMode(A2, OUTPUT) ;    //pin A3 shall be used as output
  pinMode(A3, OUTPUT) ;  //pin A2 shall be used as output
  digitalWrite(A2, HIGH) ; //set pin A3 to high (+5V)
  digitalWrite(A3,LOW) ; //set pin A3 to low (ground)
  myservo.attach(6);
}
 
void loop()
{
 delay(200);                    
 int joystickXVal = analogRead(A1) ;  //read joystick input on pin A1
 Serial.print(joystickXVal);                //print the value from A1
 Serial.println(" = input from joystick");  //print "=input from joystick" next to the value
 Serial.print((joystickXVal+520)/10);       //print a from A1 calculated, scaled value
 Serial.println(" = output to servo");      //print "=output to servo" next to the value
 Serial.println() ;
 myservo.write((joystickXVal+520)/10);      //write the calculated value to the servo  
}
