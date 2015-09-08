int sensorPins[] = {1, 2, 3, 7, 8, 9};
int sensorValues[] = {0, 0, 0, 0, 0, 0};


void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensors_average = 0;
  int sensors_sum = 0;
  for (int i = 0; i < 5; i++){
    sensorValues[i] = analogRead(sensorPins[i]);
    int value = 0;
    if (sensorValues[i] > 400) {
      value = 1;
    }
    sensors_average += value * pow(10, i);;     //Calculating the weighted mean of the sensor readings.
    sensors_sum += value; //Calculating sum of sensor readings.
  }
  Serial.print("Average ");
  Serial.print(sensors_average);
  Serial.println("");
  Serial.print("Sum ");
  Serial.print(sensors_sum);
  Serial.println("");
  Serial.print("Position ");
  Serial.print(sensors_average / sensors_sum);
  Serial.println("\n");
  delay(1000);
}
