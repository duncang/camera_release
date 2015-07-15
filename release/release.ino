#include <TimerOne.h>




const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int focusPin = 3;    // camera focus 
const int shutterPin = 4;  // camera shutter release

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status



void setup()
{

    // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  pinMode(focusPin, OUTPUT);
  pinMode(shutterPin, OUTPUT);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);  

  Serial.begin(9600);
  Serial.println("Starting");  
  
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(releaseShutter);
  
}


void releaseShutter(void)
{
  static unsigned char ucCounter = 0;
  
  ++ucCounter;
  
  if (ucCounter % 60 == 0)
  {
  
 digitalWrite(shutterPin, HIGH);
 digitalWrite(ledPin, HIGH);  
 //Serial.println("*");
 delay(10000);
 digitalWrite(shutterPin, LOW); 
 digitalWrite(ledPin, LOW); 
 
  ucCounter = 0;
 
  }
 
  
}

void loop ()
{
    // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
    digitalWrite(shutterPin,HIGH);
    
    Serial.println("#");
  
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
    digitalWrite(shutterPin, LOW);
 
  }
  
  
}


