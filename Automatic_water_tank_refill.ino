int trigpin=A5;
int echopin=A4;
int distance;
float duration;

void setup()
{
	// initialize the LCD
  Serial.begin(9600);

  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(5, OUTPUT);  // use on-board LED

   delay(400);


}

void loop()
{
 digitalWrite(trigpin,LOW);
 delay(2);
 digitalWrite(trigpin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigpin,LOW);

 duration= pulseIn(echopin,HIGH);

 distance = duration *0.034;

 Serial.println(distance);

 if(distance >=10)
  {
    digitalWrite(5,0);///pump on 

  }
  /*

   else if(distance >=3 && distance<=7)
  {
    digitalWrite(5,0);///pump on 

  }

  else if(distance > 7 && distance<=9 ) 
  {
    digitalWrite(5,0); ///[pump off]

  }
*/

  else if(distance < 10 ) 
  {
    digitalWrite(5,1); ///[pump off]

  }


 delay(200);
}






