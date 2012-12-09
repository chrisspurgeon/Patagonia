
long changeTime;


void setup() {
  pinMode(11, INPUT);
  pinMode(8, OUTPUT); //open
  pinMode(9, OUTPUT); // occupied
  Serial.begin(9600);
  
  
}

void loop() {
  Serial.println(digitalRead(11));
  if (digitalRead(11) == HIGH) {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);  
  }
}
