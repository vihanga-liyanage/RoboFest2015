int sensorPanel[10] = {};
void setup(){
  Serial.begin(9600);   //Necessary to set up Serial port
}
void loop()
{
  Serial.print(analogRead(1));
  Serial.print(' ');
  Serial.print(analogRead(2));
  Serial.print(' ');
  Serial.print(analogRead(3));
  Serial.println(' ');
  /*
  Serial.print(analogRead(7));
  Serial.print(' ');
  Serial.print(analogRead(8));
  Serial.print(' ');
  Serial.print(analogRead(9));
  Serial.println(' ');
  */
  delay(100);              //Set the number to change frequency of readings.
}
