#define RightSensor 2
#define FrontSensor 3
#define LeftSensor 4
int Rightobstacle = LOW;
int Frontobstacle = HIGH;
int Leftobstacle = LOW;
int counter = 0;
void setup()
{
  pinMode(RightSensor, INPUT);
  pinMode(FrontSensor, INPUT);
  pinMode(LeftSensor, INPUT);
}

void loop()
{
  // reads the front, right and left IR sensors
  Rightobstacle = digitalRead(RightSensor);
  Frontobstacle = digitalRead(FrontSensor);
  Leftobstacle = digitalRead(LeftSensor);
  // when there is no road left him so he will always walk to the right whatever there is road infront of him or not
  if(Rightobstacle == HIGH && Leftobstacle == LOW){
       rotate90right();
  }
  // in these case it is the same condition but in the first time he will move to the left and in the second he will move to the right 
 else if(Frontobstacle == LOW && Rightobstacle == HIGH && Leftobstacle == HIGH){
  // used counter to know if it is the 1st or 2nd time
    counter++;
    if (counter==1)
    rotate90left();
    else if(counter==2)
       rotate90right();
  } // when there is no road infront or right to him so he will walk to the left
  else if(Frontobstacle == LOW && Rightobstacle == LOW && Leftobstacle == HIGH){
       rotate90left();
  } //the rest cases he will always move forward
  else  {
        moveForward(); 
  }
}
