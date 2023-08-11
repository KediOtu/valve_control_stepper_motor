int dtime = 3; //delay time at each step
//The delay time determines the rotational speed of the motor.
//Motor driver pin connections:
#define IN1 11 
#define IN2 10 
#define IN3 9  
#define IN4 8  

void setup() {
  //output pins
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 
}
void loop() {
  // 512 Steps is one full lap. So 360degree
  ClockWise(512); //one full turn clockwise
  delay(1000);
  CntrClockWise(512);//one full turn counterclockwise
  delay(1000);
  fullOpen(5,512);//full opening of the valve
  delay(1000);
  fullClose(5,512);//full closing of the valve
  delay(1000);
}

void fullOpen(int tours, int steps){
  for(int i=1; i<=tours;i++){
    ClockWise(steps);
  }
}//function written for full opening of the valve

void fullClose(int tours, int steps){
  for(int i=1; i<=tours;i++){
    CntrClockWise(steps);
  }
}//function written for full closing of the valve

void ClockWise(int steps) {
  for (int i = 0; i < steps; i++) {
    digitalWrite(IN4, HIGH);
    delay(dtime);
    digitalWrite(IN4, LOW);
    digitalWrite(IN3, HIGH);
    delay(dtime);
    digitalWrite(IN3, LOW);
    digitalWrite(IN2, HIGH);
    delay(dtime);
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, HIGH);
    delay(dtime);
    digitalWrite(IN1, LOW);
  }
}
void CntrClockWise(int steps) {
  for (int i = 0; i < steps; i++) {
    digitalWrite(IN1, HIGH);
    delay(dtime);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    delay(dtime);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    delay(dtime);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(dtime);
    digitalWrite(IN4, LOW);
  }
}
