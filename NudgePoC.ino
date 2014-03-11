/* LED CALENDAR INDICATOR
Sketch by David Tracy
Mar 10, 2014
davidptracy.com
*/

#include <Process.h>
String eventString;
long eventLong;

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

int callCounter = 116000; 

int numRuns = 1;   // execution count, so that this doesn't run forever
int maxRuns = 10;

void setup() {
  Serial.begin(9600);  // initialize serial communication
  Bridge.begin();  // make contact with the linux processor
  
  // for debugging, wait until a serial console is connected
  delay(4000);
  while (!Serial);
  Bridge.begin();
  

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {

  callCounter ++;
  Serial.println(eventLong);
  
  eventLong = 2400; 

//  if (callCounter > 120000) {
//    
//    Serial.println("Running GetCalendarEvent");
//
//    Process getCalendarEvent;  // initialize a new process
//    getCalendarEvent.runShellCommand("python /mnt/sda1/NudgePoC02.py");  // command you want to run
//
//    // while there's any characters coming back from the
//    // process, print them to the serial monitor:
//
//    while (getCalendarEvent.available() > 0) {
//      eventString = getCalendarEvent.readStringUntil('\n');
//      eventLong = eventString.toInt();
//    }
//    callCounter = 0;
//  }
  



  if (eventLong > 3600) {
    setColor(0, 255, 0);
  }
  if (eventLong < 3600 && eventLong > 1800) {
    setColor(map(eventLong,3600,1800,0,255), 255, 0);
  }

  if (eventLong < 1800 && eventLong > 0 ) {
    setColor(255, 0, 0);
  }
  
//  delay(30000);
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

