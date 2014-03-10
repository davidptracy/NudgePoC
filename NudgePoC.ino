/* LED CALENDAR INDICATOR
Sketch by David Tracy
Mar 10, 2014
davidptracy.com
*/

#include <Process.h>
String eventString;
long eventLong;

void setup() {
  Serial.begin(9600);  // initialize serial communication  
  Bridge.begin();  // make contact with the linux processor
}

void loop() {
  Process getCalendarEvent;  // initialize a new process

  getCalendarEvent.runShellCommand("python /mnt/sda1/NudgePoC02.py");  // command you want to run

  // while there's any characters coming back from the
  // process, print them to the serial monitor:
  while (getCalendarEvent.available() > 0) {
    eventString = getCalendarEvent.readStringUntil('\n');
    eventLong = eventString.toInt();
  }
  
  Serial.println(eventLong);

  delay(5000);
}

