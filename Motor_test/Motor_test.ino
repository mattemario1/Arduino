
const int motorpin= 3;
int val = 20;
int fadeAmount = 1;

void setup() 
{
  pinMode(motorpin, INPUT);
}

void loop() 
{
  /* 
  //motor fade in fade out with for loop
  
  for (int i = 255; i >= 30; i -= 1)
  {
    analogWrite(motorpin, i);
    delay(30);
  }
  
  for (int i = 30; i <= 255; i += 1)
  {
    analogWrite(motorpin, i);
    delay(30);
  }
  */
  
  //with if
  analogWrite(motorpin, val);
  delay(30);
  
  val += fadeAmount; 
  if (val <= 20 || val >= 255)
  {
    fadeAmount = -fadeAmount;
  }
  
  
}
