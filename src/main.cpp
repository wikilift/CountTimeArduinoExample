#include <Arduino.h>

#include <utils/utils.hpp>

unsigned long myZero;
bool flag;
void setup()
{
  Serial.begin(115200);
  pinMode(inputToCount, INPUT_PULLUP);
  Serial.println("Hello");
  flag = true;
 
}

void loop()
{

  if (!digitalRead(inputToCount))
  {
    if (flag)
    {
      Serial.println("Empiezo a contar");
      myZero = giveMeTheDifference();
      flag = false;
    }
  }
  else if (digitalRead(inputToCount))
  { // entro aqui
    
    if (!flag)
    {
      unsigned long result = giveMeTheTimeElapses(myZero);
      Serial.println("Termino de contar ahora debo lanzar mi función");
      Serial.println("Han transcurrido-> " + String(result)+ "miliSegundos");
    }

    flag = true;
  }
  delay(100);
  Serial.print(".");
}