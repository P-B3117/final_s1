#include <Arduino.h>
#include <libRobus.h>
#include "bluetooth.h"
#include <SoftwareSerial.h>


// //Create software serial object to communicate with HC-05
// SoftwareSerial mySerial(1, 0); //HC-05 Tx & Rx is connected to Arduino #3 & #2


// void bluetoothInit()
// {
//       //Begin serial communication with Arduino and HC-05
//   mySerial.begin(9600);

//   Serial.println("Initializing...");
//   Serial.println("The device started, now you can pair it with bluetooth!");
// }

// void bluetoothLoop()
// {
// if(Serial.available()) 
//   {
//     mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
//   }
//   if(mySerial.available()) 
//   {
//     Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
//   }
//   delay(20);
// }






