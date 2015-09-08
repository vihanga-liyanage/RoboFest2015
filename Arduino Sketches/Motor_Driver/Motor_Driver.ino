//Coded by Vihanga Liyanage

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

void setup() {  // Setup runs once per reset
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600);
  
  //Define L298N Dual H-Bridge Motor Controller Pins
  
  pinMode(dir1PinA,OUTPUT);
  pinMode(dir2PinA,OUTPUT);
  pinMode(speedPinA,OUTPUT);
  pinMode(dir1PinB,OUTPUT);
  pinMode(dir2PinB,OUTPUT);
  pinMode(speedPinB,OUTPUT);

}

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

void hardTurn(){
  
}

