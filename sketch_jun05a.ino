void setup() {
   Serial.begin(115200);

  pinMode(13, OUTPUT);

  pinMode(12, OUTPUT);

  pinMode(11, OUTPUT);

  pinMode(10, OUTPUT);

  // delay(100);

  // put your setup code here, to run once:

}

void loop() {
   while (Steps_left > 0);

 {

    currentMillis = micros();

    if (currentMillis - last_time >= 100) 

    {

      stepper(1);

      time = time + micros() - last_time;

      last_time = micros();

      Steps_left--;

    }

  // put your main code here, to run repeatedly:

}

  Serial.println(time);


  Serial.println("Wait...!");

  delay(2000);

  Direction = !Direction;

   Steps_left = 4095;
}

 

void stepper(int xw) 

{

  for (int x = 0; x < xw; x++) 

{

    switch (Steps) 

   {

      case 0:

        digitalWrite(13, LOW);

        digitalWrite(12, LOW);

        digitalWrite(11, LOW);

        digitalWrite(10, HIGH);

        break;

      case 1:

        digitalWrite(13, LOW);

        digitalWrite(12, LOW);

        digitalWrite(11, HIGH);

        digitalWrite(10, HIGH);

        break;

      case 2:

        digitalWrite(13, LOW);

        digitalWrite(12, LOW);

        digitalWrite(11, HIGH);

        digitalWrite(10, LOW);

        break;

      case 3:

        digitalWrite(13, LOW);

        digitalWrite(12, HIGH);

        digitalWrite(11, HIGH);

        digitalWrite(10, LOW);

        break;

      case 4:

        digitalWrite(13, LOW);

        digitalWrite(12, HIGH);

        digitalWrite(11, LOW);

        digitalWrite(10, LOW);

        break;

      case 5:

        digitalWrite(13, HIGH);

        digitalWrite(12, HIGH);

        digitalWrite(11, LOW);

        digitalWrite(10, LOW);

        break;

      case 6:

        digitalWrite(13, HIGH);

        digitalWrite(12, LOW);

        digitalWrite(11, LOW);

        digitalWrite(10, LOW);

        break;

      case 7:

        digitalWrite(13, HIGH);

        digitalWrite(12, LOW);

        digitalWrite(11, LOW);

        digitalWrite(10, HIGH);

        break;

      default:

        digitalWrite(13, LOW);

        digitalWrite(12, LOW);

        digitalWrite(11, LOW);

        digitalWrite(10, LOW);

        break;

    }

    SetDirection();

  }

}

void SetDirection() 

{

  if (Direction == 1) 

{

    Steps++;

}

  if (Direction == 0) 

{

    Steps--;

}

  if (Steps > 7) 

{

    Steps = 0;

}

  if (Steps < 0) 

{

    Steps = 7;

}

}
