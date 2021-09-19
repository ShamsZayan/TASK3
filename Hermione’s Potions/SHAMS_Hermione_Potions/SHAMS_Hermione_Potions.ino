#include "Timer.h"
int Push = 7;
int redLed = 13;
int greenLed = 12;
int whiteLed = 11;
int val = HIGH;     // variable for reading the pin status
Timer mytimer;
void setup() {
pinMode(Push, INPUT);
pinMode(redLed, OUTPUT);
pinMode(greenLed, OUTPUT);
pinMode(whiteLed, OUTPUT);
//Flashes the Green LED for 5 seconds every 2 minutes
mytimer.every(120000,Green);
//Flashes the White LED for 10 seconds at 5 minutes and at 8 minutes
mytimer.after(300000,White);
mytimer.after(480000,White);
//turn off the red led after 15 min.
mytimer.after(900000,Red);

}
void Green(){
  for(int i=0;i<5;i++){
 //make led blink for 5 seconds
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a half second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a half second
    }
}
void White(){
   for(int i=0;i<10;i++){
 //make led blink for 10 seconds
    digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a half second
  digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a half second
    }
}
void Red(){
  digitalWrite(13, LOW);
}
void loop() {
  //check if button pushed or not to start the main recipe routine
  while(val==HIGH){
    val = digitalRead(Push);
  }
mytimer.update();
//turn on red led
 digitalWrite(13, HIGH);
}
