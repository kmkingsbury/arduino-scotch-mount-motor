/*     -----------------------------------------------------------
 *     |  Arduino Scotch Mount Motor Drive                       |
 *     |  by: Kevin M. Kingsbury                                 |
 *     |  http://www.kevinkingsbury.com                          |
 *     -----------------------------------------------------------
 * 
 *  Instructable:
 * 
 */
//L293D motor driver chip. L293D IC
int enablePin = 11;  
int in1Pin = 10;
int in2Pin = 9;
int torque = 250; /* 0 to 255, for simple motors this is speed. 
For the motor I'm using this is more like a torque; low values stop, high stronger. */

//Reverse Direction Button: Tactile push switch
int switchPin = 7;

// Timing Delays to get the right rotation/min.
int onTime = 500;  //the number of milliseconds for the motor to turn on for
int offTime = 500; //the number of milliseconds for the motor to turn off for


void setup()
{
  pinMode(in1Pin, OUTPUT); 
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
}


void loop()                     // run over and over again
{
 motorOnAndOff();
}

void runMotor(int speed, boolean reverse)
{
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, ! reverse);
  digitalWrite(in2Pin, reverse);
}
void stopMotor()
{
  digitalWrite(in1Pin, 0);
  digitalWrite(in2Pin, 0);
}


void motorOnAndOff(){
  boolean reverse = digitalRead(switchPin);
  runMotor(torque, reverse);
  delay(onTime);                // waits for onTime milliseconds
  stopMotor();
  delay(offTime);               // waits for offTime milliseconds
}
