#include <VirtualWire.h>

unsigned long offTime;
bool lastStatus;
long delayTime = 5000;


void setup() {
  pinMode(11, INPUT);
  pinMode(8, OUTPUT); //open
  pinMode(9, OUTPUT); // occupied
  Serial.begin(9600);

  // Initialize the IO and ISR
  vw_setup(2000); //2000 bits/sec


}

void loop() {
  if (digitalRead(11) == HIGH) {
    send("1");
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    lastStatus = true;
  } else {
    if (lastStatus == true) {
      Serial.println("OFF!");
      offTime = millis();
      lastStatus = false;
    }
    Serial.println(abs(millis() - offTime));
    if (abs(millis() - offTime) > delayTime) {
      Serial.println("OK to turn on light!");
      send("0");

      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);  
    }
  }
  delay(250);
}

void send (char *message) {
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Wait until the whole message is gone
}





