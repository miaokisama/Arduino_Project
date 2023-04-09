
// Define LED and switch connnections
const byte ledPin1 = 11;
const byte ledPin2 = 13;
const byte buttonPin1 = 2;
const byte buttonPin2 = 7;

// Boolean to represent toggle state
// (not going to be modified during the loop)
// volatile bool toggleState = false;
volatile bool D2_state = LOW;
volatile bool D7_state = LOW;

// void checkSwitch(){
//   // Switch was pressed; change state of toggle
//   toggleState = !toggleState;
//   // Indicate state on LED
//   digitalWrite(ledPin, toggleState);
// }

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  // Serial.begin(9600);
  // Check the intterrupt on a fallimg pulse
  // attachInterrupt( digitalPinToInterrupt(buttonPin), checkSwitch, FALLING);
  // Enable PCIE2 Bit3 = 1(port D, Pin D7)
  PCICR |= B00000100;
  PCMSK2 |= B10000100;

}

void loop() {
  // // 5s time delay
  // Serial.println("Delay Started");
  // delay(5000);
  // Serial.println("Delay Finished");
  // Serial.println("--------------");
}

ISR(PCINT2_vect){
  if(digitalRead(buttonPin1) == LOW){
    D2_state = !D2_state;
    digitalWrite(ledPin1, D2_state);
  }
  if(digitalRead(buttonPin2) == LOW){
    D7_state = !D7_state;
    digitalWrite(ledPin2, D7_state);
  }
}