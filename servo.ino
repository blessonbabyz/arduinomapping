#include<Servo.h>
int servom1 =9;
int servom2 = 10;
int xangle;
int yangle;
Servo servo1;
Servo servo2;

void setup()
{
  Serial.begin(9600);
  servo1.attach(servom1);
  servo2.attach(servom2);
}
void loop()
{
  if(Serial.available())
    {
     int xdata = Serial.readStringUntil(',').toInt();
     int ydata = Serial.readString().toInt();
     //int xdata=Serial.parseInt();
     //int ydata=Serial.parseInt();
      if((xdata<180)&&(xdata>0)&&(ydata<180)&&(ydata>0))
       {
        xangle=xdata;
        yangle=ydata;
       }
      else 
       {
        xangle=90;
        yangle=90;
       }
      Serial.println(xangle);
      servo1.write(xangle);
      delay(200);
      Serial.println(yangle);
      servo2.write(yangle);
      delay(200);
    }
}
  
