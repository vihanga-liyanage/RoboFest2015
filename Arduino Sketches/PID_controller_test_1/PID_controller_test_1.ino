long sensors_average;
int sensors_sum;
int Position;
int sensorPins[] = {1, 2, 3, 7, 8, 9, 10};
long sensorValues[] = {0, 0, 0, 0, 0, 0, 0};   // Array used to store 5 readings for 5sensors.
 
void setup(){
 Serial.begin(9600);
}
 
void loop(){
  sensors_average = 0;
  sensors_sum = 0;
   
  for (int i = 0; i < 5; i++){
  sensorValues[i] = analogRead(i);
  Serial.print(int(sensorValues[i]));
  Serial.print(" ");
  
  }
  Serial.print("\n");
  delay(2000);
//  sensors_average += sensorValues[i] * i * 1000;   //Calculating the weighted mean
//  sensors_sum += int(sensorValues[i]);}            //Calculating sum of sensor readings
//  Position = int(sensors_average / sensors_sum);
//  Serial.print("Average : ");
//  Serial.print(sensors_average);
//  Serial.println(' ');
//  Serial.print("Sum : ");
//  Serial.print(sensors_sum);
//  Serial.println(' ');
//  Serial.print("Position : ");
//  Serial.print(Position);
//  Serial.println(' ');
//  Serial.println(' ');
}
