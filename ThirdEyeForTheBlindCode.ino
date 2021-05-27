const int pingTrigPin = 13;
const int pingEchoPin = 12;
const int pingTrigPin2 = 11;
const int pingEchoPin2 = 10;
int buz1=6;
int motor1=7;
int buz2=4;
int motor2=5;
void setup() {
Serial.begin(9600);
{pinMode(buz1, OUTPUT);
pinMode(motor1,OUTPUT);
pinMode(buz2, OUTPUT);
pinMode(motor2,OUTPUT); }
}
void loop()
{
long duration, cm;
pinMode(pingTrigPin, OUTPUT);
digitalWrite(pingTrigPin, LOW);
delayMicroseconds(2);
digitalWrite(pingTrigPin, HIGH);
delayMicroseconds(5);
digitalWrite(pingTrigPin, LOW);
pinMode(pingEchoPin, INPUT);
duration = pulseIn(pingEchoPin, HIGH);
cm = microsecondsToCentimeters(duration);
if(cm<=50 && cm>0)

{
int d= map(cm, 1, 100, 20, 2000);
{digitalWrite(buz1, HIGH);
}
delay(100);
{digitalWrite(buz1, LOW);
}
delay(d);
}
Serial.print(cm);
Serial.print("cm(1)");
Serial.println();
delay(100);

if (cm < 15)
digitalWrite(motor1,HIGH);
else
digitalWrite(motor1,LOW);
delay(100);

long duration2, cms;
pinMode(pingTrigPin2, OUTPUT);
digitalWrite(pingTrigPin2, LOW);
delayMicroseconds(2);
digitalWrite(pingTrigPin2, HIGH);
delayMicroseconds(5);
digitalWrite(pingTrigPin2, LOW);
pinMode(pingEchoPin2, INPUT);
duration2 = pulseIn(pingEchoPin2, HIGH);
cms = microsecondsToCentimeters(duration2);
if(cms<=50 && cms>0)
{

int d2= map(cms, 1, 100, 20, 2000);
{digitalWrite(buz2, HIGH);
}
delay(100);
{digitalWrite(buz2, LOW);
}
delay(d2);
}
Serial.print(cms);
Serial.print("cm(2)");
Serial.println();
delay(100);

if (cms < 15)
digitalWrite(motor2,HIGH);
else
digitalWrite(motor2,LOW);
delay(100);
}

long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}
