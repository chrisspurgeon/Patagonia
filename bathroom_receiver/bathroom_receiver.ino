#include <VirtualWire.h>
byte message[VW_MAX_MESSAGE_LEN]; // a buffer to hold the incoming messages 
byte msgLength = VW_MAX_MESSAGE_LEN; // the size of the message


boolean onLight;
boolean offLight;

void setup() {
  Serial.begin(9600); 
  Serial.println("Ready");
  // Initialize the IO and ISR
  vw_setup(2000); // Bits per sec
  vw_rx_start(); // Start the receiver 

  pinMode(8, OUTPUT);  //offLight
  pinMode(9, OUTPUT); //onLight


}

void loop() {
  digitalWrite(8, offLight);
  digitalWrite(9, onLight);
  if (vw_get_message(message, &msgLength)) {
    Serial.print("Got: ");
    for (int i = 0; i < msgLength; i++) {
      Serial.write(message[i]); 
      if (message[i] == '1') {
        Serial.println("Light on!");
        onLight = HIGH;
        offLight = LOW;
      } 
      else if (message[i] == '0') {
        Serial.println("Light off!");
        onLight = LOW;
        offLight = HIGH;
      }
    }
    Serial.println();
  } 
}



