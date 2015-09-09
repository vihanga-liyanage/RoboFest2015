// sensors
int IR1, IR2, IR3, IR4, IR5, IR6;
//sensor pins
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
  IR1 = analogRead(1) + leftOffset;
  IR2 = analogRead(2);
  IR3 = analogRead(3) + rightOffset;
  
  if (IR1 > (IR3 + threshhold)) {
    left = startSpeed + rotate;
    right = startSpeed - rotate;
  } else if (IR3 > (IR1 + threshhold)){
    left = startSpeed - rotate;
    right = startSpeed + rotate;
  }
  */
  //special code
  IR1 = valueDegitalizer(analogRead(3));
  IR2 = valueDegitalizer(analogRead(7));
  IR3 = valueDegitalizer(analogRead(8));
  
  
  Serial.print(IR1);
  Serial.print(" ");
  Serial.print(IR2);
  Serial.print(" ");
  Serial.println(IR3);
  
  if (IR1 > (IR3)) {
    left = startSpeed + rotate;
    right = startSpeed - rotate;
  } else if (IR3 > (IR1)){
    left = startSpeed - rotate;
    right = startSpeed + rotate;
  }
  if ((IR1 == IR2) && (IR1 == IR3)){
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
