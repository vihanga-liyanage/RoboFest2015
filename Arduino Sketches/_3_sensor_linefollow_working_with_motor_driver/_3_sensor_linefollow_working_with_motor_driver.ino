int LDR1, LDR2, LDR3; // sensor values
// calibration offsets
int leftOffset = 0, rightOffset = 0, centre = 0;
// starting speed and rotation offset
int startSpeed = 70, rotate = 30; 
/* CHANGE START SPEED IF YOUR ROBOT IS TOO SLOW, AND CHANGE THE ROTATE VALUE ACCORDING TO YOUR 
TURNING ANGLE OF BLACK LINE.*/
// sensor threshold
int threshhold = 2;
// initial speeds of left and right motors
int left = startSpeed, right = startSpeed;

//For motor driving====================================
// Left Motor
int dir1PinA = 22;
int dir2PinA = 24;
int speedPinA = 2; // Needs to be a PWM pin to be able to control motor speed
int leftMotorOffset = 0; //Try changing this if motors have different speeds

// Right Motor
int dir1PinB = 26;
int dir2PinB = 28;
int speedPinB = 3; // Needs to be a PWM pin to be able to control motor speed
int rightMotorOffset = 0; //Try changing this if motors have different speeds

void drive(int leftSpeed, int rightSpeed, boolean forward){ //if forward == false, drive reverse
  // Left Motor
  analogWrite(speedPinA, leftSpeed - leftMotorOffset);
  if (forward){
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, HIGH);
  } else {
    digitalWrite(dir1PinA, HIGH);
    digitalWrite(dir2PinA, LOW);
  }

  // Right Motor
  analogWrite(speedPinB, rightSpeed - rightMotorOffset);
  if (forward){
    digitalWrite(dir1PinB, LOW);
    digitalWrite(dir2PinB, HIGH);
  } else {
    digitalWrite(dir1PinB, HIGH);
    digitalWrite(dir2PinB, LOW);
  }
}
//=============================================================================
// Sensor calibration routine
void calibrate() {
  for (int x=0; x<10; x++) { // run this 10 times to obtain average
    
    LDR1 = analogRead(1); // read the 3 sensors
    LDR2 = analogRead(2);
    LDR3 = analogRead(3);

    Serial.print("Reading ");
    Serial.println(x + 1);
    
    leftOffset = leftOffset + LDR1; // add value of left sensor to total
    centre = centre + LDR2; // add value of centre sensor to total
    rightOffset = rightOffset + LDR3; // add value of right sensor to total
  }
  // obtain average for each sensor
  leftOffset = leftOffset / 10;
  rightOffset = rightOffset / 10;
  centre = centre /10;
  // calculate offsets for left and right sensors
  leftOffset = centre - leftOffset;
  rightOffset = centre - rightOffset;
  Serial.println("Left centre right");
  Serial.print(leftOffset);
  Serial.print(" ");
  Serial.print(centre);
  Serial.print(" ");
  Serial.println(rightOffset);
  Serial.println("Calibrate done.");
}

void setup(){
  Serial.begin(9600);
  // set the motor pins to outputs
  pinMode(dir1PinA,OUTPUT);
  pinMode(dir2PinA,OUTPUT);
  pinMode(speedPinA,OUTPUT);
  pinMode(dir1PinB,OUTPUT);
  pinMode(dir2PinB,OUTPUT);
  pinMode(speedPinB,OUTPUT);
  // calibrate the sensors
  calibrate();
  // set speed of both motors
  analogWrite(speedPinA,left);
  analogWrite(speedPinB,right);
}

int valueDegitalizer(int value){
  if (value > 500) {
    return 5; 
  } else if (value < 10){
    return 0;
  } else {
    return 5;
  }
}

void loop() {
  // make both motors same speed
  left = startSpeed;
  right = startSpeed;
  // read the sensors and add the offsets
  /*
  LDR1 = analogRead(1) + leftOffset;
  LDR2 = analogRead(2);
  LDR3 = analogRead(3) + rightOffset;
  
  if (LDR1 > (LDR3 + threshhold)) {
    left = startSpeed + rotate;
    right = startSpeed - rotate;
  } else if (LDR3 > (LDR1 + threshhold)){
    left = startSpeed - rotate;
    right = startSpeed + rotate;
  }
  */
  //special code
  LDR1 = valueDegitalizer(analogRead(3));
  LDR2 = valueDegitalizer(analogRead(7));
  LDR3 = valueDegitalizer(analogRead(8));
  
  
  Serial.print(LDR1);
  Serial.print(" ");
  Serial.print(LDR2);
  Serial.print(" ");
  Serial.println(LDR3);
  
  if (LDR1 > (LDR3)) {
    left = startSpeed + rotate;
    right = startSpeed - rotate;
  } else if (LDR3 > (LDR1)){
    left = startSpeed - rotate;
    right = startSpeed + rotate;
  }
  if ((LDR1 == LDR2) && (LDR1 == LDR3)){
    left = 0;
    right = 0;
  }
  
  Serial.print(left);
  Serial.print(" ");
  Serial.print(right);
  Serial.println("");
  drive(left, right, true);
  //delay(500);
  
}
