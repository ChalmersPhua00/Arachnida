// Arachnida Mark 1.0
// Chalmers Phua
const int buttonPin = 2;

int currentButtonState = 0;
int lastButtonState = 0;
int count = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  currentButtonState = digitalRead(buttonPin);
  if (currentButtonState != lastButtonState && currentButtonState == LOW) {
    count = 1;
  } else if (currentButtonState == lastButtonState && currentButtonState == LOW) {
    count++;
  }
 
  if (count >= 1 && count <= 15) {
    Serial.println("calibration");
  } else if (count >= 11 && count <= 30) {
    Serial.println("rotateLeft");
  } else if (count >= 31 && count <= 50) {
    Serial.println("rotateRight");
  } else if (count >= 51 && count <= 70) {
    Serial.println("forward");
  } else if (count >= 71 && count <= 90) {
    Serial.println("backward");
  }
 
  lastButtonState = currentButtonState;
  delay(50);
}
