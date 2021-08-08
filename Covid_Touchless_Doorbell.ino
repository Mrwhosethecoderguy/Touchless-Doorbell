int relay_pin = D8;
int echoPin = D10;
int trigPin = D9; 
 

void setup() {
  // put your setup code here, to run once:
  pinMode(relay_pin,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(115200);
  digitalWrite(relay_pin,HIGH);

}

float CalcDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  double duration = pulseIn(echoPin,HIGH);
  float distance = duration*0.034/2;
  return distance;
}


void loop() {
  // put your main code here, to run repeatedly:
  float distance = CalcDistance();
  if (distance < 8.0) {
    digitalWrite(relay_pin,LOW);
    delay(1000);
  }
  Serial.println(distance);
  delay(1000);
  digitalWrite(relay_pin,HIGH);
}
