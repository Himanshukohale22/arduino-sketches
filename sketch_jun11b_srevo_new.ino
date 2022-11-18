#include<Servo.h>
int pos;
Servo Myservo;
void setup() {
Myservo.attach(3);
  

  // put your setup code here, to run once:

}

void loop() {
  for(pos=0;pos<=360;pos++)
  
  Myservo.write(pos);
  delay(15);
  }
  // put your main code here, to run repeatedly:


delay(1000);
for(pos=360;pos>=0;pos--)
{
  Myservo.write(pos);
  delay(15);
}
  delay(1000);
}
