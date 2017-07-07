#include <Servo.h> // this includes the Arduino servo library

Servo base; // pin 9
Servo elbow; // pin 11
Servo claw; // pin 10

int baseDegrees = 0;
int elbowDegrees = 0;
int clawDegrees = 90;
int prevBaseDegrees;
int prevElbowDegrees;
int tempDegree = 0;
int servoWriteSpeed = 10; // this number divided by 1000 is how many times the servo updates per second

String functionStr = "";
String tempDegreeStr = "";
String incomingString = "";

void setup() {
  Serial.begin(9600);
  while (! Serial);
// binding pins
base.attach(9);
elbow.attach(11);
claw.attach(10);
delay(1000);
// resetting positions
base.write(baseDegrees);
Serial.println("Base at ");
Serial.println(baseDegrees);
delay(1000);

elbow.write(elbowDegrees);
Serial.println("Elbow at ");
Serial.println(elbowDegrees);
delay(1000);

claw.write(clawDegrees);
Serial.println("Claw at ");
Serial.println(clawDegrees);

Serial.println("Ready for input");
}

void loop() {
  
        }

        void serialEvent()
        {
          prevBaseDegrees = baseDegrees;
          prevElbowDegrees = elbowDegrees;
  incomingString = Serial.readString();
   Serial.println("Input Recieved");
   functionStr = incomingString.substring(0, 5);
   tempDegreeStr = incomingString.substring(5, 8);
   Serial.println(functionStr);
   Serial.println(tempDegreeStr);
   
  if (functionStr == "base ")
  {
    tempDegree = tempDegreeStr.toInt();
    baseDegrees = tempDegree;
    }
    
    else if (functionStr == "elbow")
    {
       tempDegree = tempDegreeStr.toInt();
       elbowDegrees = tempDegree;
      }
      
      else if (functionStr == "claw ")
      {
         tempDegree = tempDegreeStr.toInt();
    clawDegrees = tempDegree;
        }
        
        else if (functionStr == "reset")
        {
          baseDegrees = 0;
          elbowDegrees = 0;
          clawDegrees = 90;
        }
        
        else
        {
          Serial.println("Invalid input");
        }

        if (elbowDegrees > prevElbowDegrees)
        {
          for (int i = prevElbowDegrees; i <= elbowDegrees; i++)
          {
            delay(servoWriteSpeed);
            elbow.write(i);
          }
        }
        else if (elbowDegrees < prevElbowDegrees)
        {
          for (int i = prevElbowDegrees; i >= elbowDegrees; i--)
          {
            delay(servoWriteSpeed);
            elbow.write(i);
          }
        }
        if (baseDegrees > prevBaseDegrees)
        {
          for (int i = prevBaseDegrees; i <= baseDegrees; i++)
          {
            delay(servoWriteSpeed);
            base.write(i);
          }
        }
        else if (baseDegrees < prevBaseDegrees)
        {
          for (int i = prevBaseDegrees; i >= baseDegrees; i--)
          {
            delay(servoWriteSpeed);
            base.write(i);
          }
        }
        
        claw.write(clawDegrees);
        Serial.println("");
        Serial.println(baseDegrees);
        Serial.println(elbowDegrees);
        Serial.println(clawDegrees);
        Serial.println("Degrees written, thank you.");
        delay(2000);
        Serial.println("Ready for input");
        }
