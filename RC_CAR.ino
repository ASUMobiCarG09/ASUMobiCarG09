#include <SoftwareSerial.h>
#define mRP 2 // Right Postive
#define mRN 4 // Right Negative
#define mLP 7 // Left Postive
#define mLN 8 // Left Negative
int Distance0; //Forward
int Distance1; //Right
int Distance2; //Left
/**********Functions*************/
void forward()
{
digitalWrite(mRP, HIGH);
digitalWrite(mRN, LOW);
digitalWrite(mLP, HIGH);
digitalWrite(mLN, LOW);
 for(int i=0;i<150;i++)
  {
    analogWrite(6,i);
    analogWrite(9,i);
  }
  digitalWrite(13,HIGH);
}

void bridge()
{
digitalWrite(mRP, HIGH);
digitalWrite(mRN, LOW);
digitalWrite(mLP, HIGH);
digitalWrite(mLN, LOW);
 for(int i=0;i<255;i++)
  {
    analogWrite(6,i);
    analogWrite(9,i);
  }
  digitalWrite(13,HIGH);
}

void backward()
{
digitalWrite(mRP, LOW);
digitalWrite(mRN, HIGH);
digitalWrite(mLP, LOW);
digitalWrite(mLN, HIGH);
 for(int i=0;i<150;i++)
  {
    analogWrite(6,i);
    analogWrite(9,i);
  }
  digitalWrite(13,HIGH);
}

void Stop()
{
digitalWrite(mRP, LOW);
digitalWrite(mRN, LOW);
digitalWrite(mLP, LOW);
digitalWrite(mLN, LOW);
}
void SlightRight()
{ 
  digitalWrite (mRP,HIGH);
  digitalWrite(mRN, LOW);
  digitalWrite(mLP, LOW);
  digitalWrite(mLN, LOW);
   for(int i=0;i<150;i++)
  {
    analogWrite(9,i);
  }
  digitalWrite(5,HIGH);
  }
void SlightLeft ()
{
  digitalWrite (mRP,LOW);
  digitalWrite(mRN, LOW);
  digitalWrite(mLP, HIGH);
  digitalWrite(mLN, LOW);
   for(int i=0;i<150;i++)
  {
    analogWrite(6,i);
  }
  digitalWrite(12,HIGH);
}
  void Right()
  {
    digitalWrite(mRP,HIGH);
    digitalWrite(mRN, LOW);
    digitalWrite(mLP, LOW);
    digitalWrite(mLN, HIGH);
     for(int i=0;i<100;i++)
  {
    analogWrite(6,i);
    analogWrite(9,i);
  }
  digitalWrite(5,HIGH);
    }
   void Left()
   {
    digitalWrite (mRP,LOW);
    digitalWrite(mRN, HIGH);
    digitalWrite(mLP, HIGH);
    digitalWrite(mLN, LOW);
     for(int i=0;i<100;i++)
  {
    analogWrite(6,i);
    analogWrite(9,i);
  }
  digitalWrite(12,HIGH);
    }
/****************End of Functions****************/
int RX = 10;
int TX = 11;
SoftwareSerial bluetooth(TX, RX);
void setup() {
Serial.begin(9600);
bluetooth.begin(9600);
pinMode (48,OUTPUT); //trig0
pinMode (49, INPUT); //echo0
pinMode(50, OUTPUT); //trig1
pinMode(51,INPUT); //echo1
pinMode(52,OUTPUT); //trig2
pinMode(53,INPUT); //echo2
pinMode(mRP, OUTPUT);
pinMode(mRN, OUTPUT);
pinMode(mLP, OUTPUT);
pinMode(mLN, OUTPUT);
pinMode (5,OUTPUT); //Yellow_LED
pinMode(12,OUTPUT); //Red_LED
pinMode(3,OUTPUT); //Blue_LED
pinMode(6,OUTPUT); //ENA
pinMode(9,OUTPUT); //ENB
pinMode(13,OUTPUT); //Green_LED
}

void loop() {
  while(bluetooth.available())
{
Serial.println("BLUETOOTH AVAILABLE");
digitalWrite(3,HIGH); 
char data = bluetooth.read();
if(data =='1') // forward
{  
Serial.println("Forward");
forward();
}
else if(data =='7') // bridge
{  
Serial.println("Bridge");
bridge();
}
else if(data =='8') //backward
{
Serial.println("Backward");
backward();

}
else if(data =='0') //stop
{
Serial.println("Stop");
Stop();
}
else if ( data =='3') //SlightRight
{
  Serial.println("Slight Right");
  SlightRight ();
}
else if( data=='4') //Slight Left
{
  Serial.println("Slight Left");
  SlightLeft ();
}
else if (data=='5') //Right
{
  Serial.println ("Right");
  Right ();
}
else if (data =='6') //Left
{
  Serial.println("Left");
  Left();
}
else if( data=='2') //UltraSonic
{
 Serial.println("Forward");
forward(); 
digitalWrite(48,HIGH); //TRIG0
delay(250);
digitalWrite(48,LOW); //TRIG0
int time = pulseIn(49,HIGH); //ECHO0
Distance0 = time/(2*29.1);
delay(250);
if (Distance0 <25 && Distance0 >0)
{
  Stop();
digitalWrite(50,HIGH); //TRIG1
delay(250);
digitalWrite(50,LOW); //TRIG1
int time = pulseIn(51,HIGH); //ECHO1
Distance1 = time/(2*29.1);
delay(250);

if (Distance1 <25 && Distance1 >0)
{
digitalWrite(52,HIGH); //TRIG2
delay(250);
digitalWrite(52,LOW); //TRIG2
int time = pulseIn(53,HIGH); //ECHO2
Distance2 = time/(2*29.1); 
if(Distance2 <25 && Distance2 >0)
{
  Stop();
  }
  else
  {
    Left();
    delay(5);
    Stop();
    break;
  }
}
else
{
  Right();
  delay(5);
  Stop();
  break;
  }
  }
}
}
}
