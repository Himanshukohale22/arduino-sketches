int servopin=10;// select digital pin 10 for servo motor signal line

int myangle;// initialize angle variable

int pulsewidth;// initialize width variable

int val;



void servopulse(int servopin,int myangle) // define a servo pulse function

{

pulsewidth=(myangle*11)+500;// convert angle to 500-2480 pulse width

digitalWrite(servopin,HIGH);// set the level of servo pin as “high”

delayMicroseconds(pulsewidth);// delay microsecond of pulse width

digitalWrite(servopin,LOW);// set the level of servo pin as “low”

delay(20-pulsewidth/1000);

}

 

/* The setup() function is called when a sketch starts. It is used to initialize variables, pin modes, start using libraries, etc. This function will only run once, after each power up or reset of the Arduino board. */

 

void setup()

{

pinMode(servopin,OUTPUT);
Serial.begin(9600);// connect to serial port, set baud rate at “9600”

Serial.println("servo=o_seral_simple ready" ) ;
void loop();{ 


val=Serial.read();// read serial port value

if(val>='0'&&val<='6')

{

val=val-'0';// convert characteristic quantity to numerical variable

val=val*(180/6);// convert number to angle

Serial.print("moving servo to ");

Serial.print(val,DEC);

Serial.println();

for(int i=0;i<=50;i++) // giving the servo time to rotate to commanded position

{

servopulse(servopin,val);// use the pulse function:
}
}
}
