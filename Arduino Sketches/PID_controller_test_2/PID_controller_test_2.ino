long sensors_average;
int sensors_sum;
int set_point = 1792;
int position;
int proportional, integral, last_proportional, error_value, derivative;
int sensorPins[] = {1, 2, 3, 7, 8, 9};
long sensorValues[] = {0, 0, 0, 0, 0, 0};   // Array used to store 5 readings for 5sensors.

//PID constants
int Kp = 0;
int Ki = 0;
int Kd = 0;


void read_sensors(){
  sensors_average = 0;
  sensors_sum = 0;
  for (int i = 0; i < 5; i++){
    sensorValues[i] = analogRead(sensorPins[i]);
     
    sensors_average += sensorValues[i] * i * 1000;     //Calculating the weighted mean of the sensor readings.
    sensors_sum += int(sensorValues[i]); //Calculating sum of sensor readings.
   
  }
}

void pid_calc(){
  position = int(sensors_average / sensors_sum);
  proportional = position - set_point;
  integral = integral + proportional;
  derivative = proportional - last_proportional;
  last_proportional = proportional;
   
  error_value = int(proportional * Kp + integral * Ki + derivative * Kd);
  Serial.println(error_value);
}

void setup(){
 Serial.begin(9600);
}
 
void loop(){
  read_sensors();
  pid_calc();
}

/*
void calc_turn(){  //Restricting the error value between +256.
  if (error_value < -256){ 
    error_value = -256;     
  } 
  
  if (error_value > 256){
    error_value = 256;
  }
 
// If error_value is less than zero calculate right turn speed values
  if (error_value< 0){
    right_speed = max_speed + error_value;
    left_speed = max_speed;
  }
 
// Iferror_value is greater than zero calculate left turn values
   
  else{
    right_speed = max_speed;
    left_speed = max_speed - error_value;
  }
}*/
