int switchPin = 2; // switch input
int motor1Pin1 = 8; // pin 2 on L293D
int motor1Pin2 = 6; // pin 7 on L293D
int motor1Pin11 = 3; // pin 2 on L293D
int motor1Pin22 = 4;

const int trigPin = 9;
const int echoPin =10 ;

void setup() {
    // set the switch as an input:
    pinMode(switchPin, INPUT);

    // set all the other pins you're using as outputs:
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor1Pin11, OUTPUT);
    pinMode(motor1Pin22, OUTPUT);
   
}

void loop() {
    // if the switch is high, motor will turn on one direction:
    if (digitalRead(switchPin) == HIGH) {
        digitalWrite(motor1Pin1, HIGH); // set pin 2 on L293D low
        digitalWrite(motor1Pin2, LOW);
        digitalWrite(motor1Pin11, HIGH); // set pin 2 on L293D low
        digitalWrite(motor1Pin22, LOW);
        digitalWrite (13,HIGH); // set pin 7 on L293D high
    }
    // if the switch is low, motor will turn in the opposite direction:
    else {
        digitalWrite(motor1Pin1, LOW); // set pin 2 on L293D high
        digitalWrite(motor1Pin2, HIGH);
       digitalWrite(motor1Pin11, LOW); // set pin 2 on L293D low
        digitalWrite(motor1Pin22, HIGH); 
        
       long duration, duration1, x, y;
 

  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  
   y = microsecondsToCentimeters(duration);
  
  
  if (y<=10)
  {
    digitalWrite(motor1Pin11, LOW); // set pin 2 on L293D low
        digitalWrite(motor1Pin22, LOW); 
        
     delay (10000);
     digitalWrite(motor1Pin11, LOW); // set pin 2 on L293D low
        digitalWrite(motor1Pin22, HIGH); 
       }
    }
}
long microsecondsToCentimeters(long microseconds)
{
 
  return microseconds / 29 / 2;
}
