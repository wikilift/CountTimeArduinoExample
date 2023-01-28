#include <Arduino.h>

#include <utils/utils.hpp>

unsigned long myZero;
bool flag;
void setup()
{
  Serial.begin(115200);
  pinMode(inputToCount, INPUT_PULLUP);
 
  flag = true;
 
}

void loop()
{

  if (!digitalRead(inputToCount))
  {
    if (flag)
    {
      Serial.println("Counter started");
      myZero = giveMeTheDifference();
      flag = false;
    }
  }
  else if (digitalRead(inputToCount))
  { 
    
    if (!flag)
    {
      unsigned long result = giveMeTheTimeElapses(myZero);
      Serial.println("Counter finished,must launch my function");
      Serial.println("Elapsed-> " + String(result)+ "miliseconds");
    }

    flag = true;
  }
  delay(100);
  Serial.print(".");
}
