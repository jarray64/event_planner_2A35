#include <SoftwareSerial.h>
SoftwareSerial mySerial(7, 8);
char msg;
char call;

char getNumber;

String  number="";


char data;
void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  Serial.println("GSM SIM900A BEGIN");
  Serial.println("Enter character for control option:");
  Serial.println("h : to disconnect a call");
  Serial.println("i : to receive a call");
  Serial.println("s : to send message");
  Serial.println("c : to make a call");  
  Serial.println("e : to redial");
  Serial.println();
 
    
  delay(100);
}

char rx_byte = 0;
String rx_str = "";

void loop()
{

  
  
  if (Serial.available()>0)


   
   switch(Serial.read())
  {
    case 'a':
      MakeCallabdo();
      break;
    case 'b':
      MakeCallhadil();
      break;
       case 'c':
      MakeCallahmed();
      break;
    
  }
 if (mySerial.available()>0) 
 Serial.write(mySerial.read());

 
 
}





void MakeCallabdo()
{
  
  mySerial.println("ATD+21652940699;"); // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
  Serial.println("Calling  "); // print response over serial port
  delay(1000);
}


void MakeCallhadil()
{
  
  mySerial.println("ATD+21624262449;"); // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
  Serial.println("Calling  "); // print response over serial port
  delay(1000);
}
void MakeCallahmed()
{
  
  mySerial.println("ATD+21653273182;"); // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
  Serial.println("Calling  "); // print response over serial port
  delay(1000);
}
