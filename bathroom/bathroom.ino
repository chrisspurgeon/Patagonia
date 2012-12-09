
unsigned long offTime;
bool lastStatus;
long delayTime = 5000;


void setup() {
  pinMode(11, INPUT);
  pinMode(8, OUTPUT); //open
  pinMode(9, OUTPUT); // occupied
  Serial.begin(9600);


}

void loop() {
  if (digitalRead(11) == HIGH) {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    lastStatus = true;
  } 
  else {
    if (lastStatus == true) {
      Serial.println("OFF!");
      offTime = millis();
      lastStatus = false;
    }
    if (abs(millis() - offTime) > delayTime) {
      Serial.println("OK to turn on light!");
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);  
    }
  }
}


