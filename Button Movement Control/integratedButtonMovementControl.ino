// Arachnida Mark 1.0
// Chalmers Phua
#include <Servo.h>

Servo U3hor;
Servo U1ver;
Servo U6hor;
Servo U4ver;
Servo U9hor;
Servo U7ver;
Servo U10hor;
Servo U12ver;
Servo U15hor;
Servo U13ver;
Servo U18hor;
Servo U16ver;

int def_deg = 90;
int max_deg_hor = 110;
int min_deg_hor = 70;
int max_deg_ver = 140;
int min_deg_ver = 40;
int state = 1;
int action = 0;

const int buttonPin = 2;
int currentButtonState = 0;
int lastButtonState = 0;
int count = 0;

void setup() {
  int tempo = 120;
  int buzzerPin = 53;
  int melody[] = {587, -4, 659, -4, 440, 4, 659, -4, 740, -4, 880, 16, 784, 16, 740, 8, 587, -4, 659, -4, 440, 2, 440, 16, 440, 16, 494, 16, 587, 8, 587, 16, 587, -4, 659, -4, 440, 4, 659, -4, 740, -4, 880, 16, 784, 16, 740, 8, 587, -4, 659, -4, 440, 2, 440, 16, 440, 16, 494, 16, 587, 8, 587, 16};  
  int notes = sizeof(melody)/sizeof(melody[0])/2;
  int wholenote = (60000*4)/tempo;
  int divider = 0;
  int noteDuration = 0;
  for (int thisNote = 0; thisNote < notes*2; thisNote = thisNote+2) {
    divider = melody[thisNote+1];
    if (divider > 0) {
      noteDuration = (wholenote)/divider;
    } else if (divider < 0) {
      noteDuration = (wholenote)/abs(divider);
      noteDuration *= 1.5;
    }
    tone(buzzerPin, melody[thisNote], noteDuration*0.9);
    delay(noteDuration);
    noTone(buzzerPin);
  }
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
  if (count >= 1 && count <= 13) {
    Serial.println("calibration");
    action = 0;
    U3hor.attach(24);
    U3hor.write(def_deg);
    U1ver.attach(22);
    U1ver.write(def_deg);
    U6hor.attach(30);
    U6hor.write(def_deg);
    U4ver.attach(28);
    U4ver.write(def_deg);
    U9hor.attach(33);
    U9hor.write(def_deg);
    U7ver.attach(31);
    U7ver.write(def_deg);
    U10hor.attach(39);
    U10hor.write(def_deg);
    U12ver.attach(37);
    U12ver.write(def_deg);
    U15hor.attach(42);
    U15hor.write(def_deg);
    U13ver.attach(40);
    U13ver.write(def_deg);
    U18hor.attach(43);
    U18hor.write(def_deg);
    U16ver.attach(45);
    U16ver.write(def_deg);
  } else if (count >= 14 && count <= 16) {
    Serial.println("left");
    if (action != 1) {
      action = 1;
      state = 1;
    }
    if (state == 1) {
      defMin(U3hor, U1ver);
      defDef(U6hor, U4ver);
      defMin(U9hor, U7ver);
      defDef(U10hor, U12ver);
      defMin(U15hor, U13ver);
      defDef(U18hor, U16ver);
      state = 2;
    } else if (state == 2) {
      maxDef(U3hor, U1ver);
      minDef(U6hor, U4ver);
      maxDef(U9hor, U7ver);
      minDef(U10hor, U12ver);
      maxDef(U15hor, U13ver);
      minDef(U18hor, U16ver);
      state = 3;
    } else {
      defDef(U3hor, U1ver);
      defDef(U6hor, U4ver);
      defDef(U9hor, U7ver);
      defDef(U10hor, U12ver);
      defDef(U15hor, U13ver);
      defDef(U18hor, U16ver);
      state = 1;
    }
    delay(300);
  } else if (count >= 17 && count <= 19) {
    Serial.println("right");
    if (action != 2) {
      action = 2;
      state = 1;
    }
    if (state == 1) {
      defMin(U3hor, U1ver);
      defDef(U6hor, U4ver);
      defMin(U9hor, U7ver);
      defDef(U10hor, U12ver);
      defMin(U15hor, U13ver);
      defDef(U18hor, U16ver);
      state = 2;
    } else if (state == 2) {
      minDef(U3hor, U1ver);
      maxDef(U6hor, U4ver);
      minDef(U9hor, U7ver);
      maxDef(U10hor, U12ver);
      minDef(U15hor, U13ver);
      maxDef(U18hor, U16ver);
      state = 3;
    } else {
      defDef(U3hor, U1ver);
      defDef(U6hor, U4ver);
      defDef(U9hor, U7ver);
      defDef(U10hor, U12ver);
      defDef(U15hor, U13ver);
      defDef(U18hor, U16ver);
      state = 1;
    }
    delay(300);
  } else if (count >= 20 && count <= 22) {
    Serial.println("forward");
    if (action != 3) {
      action = 3;
      state = 1;
    }
    if (state == 1) {
      defMin(U3hor, U1ver);
      defDef(U6hor, U4ver);
      defMin(U9hor, U7ver);
      defDef(U10hor, U12ver);
      defMin(U15hor, U13ver);
      defDef(U18hor, U16ver);
      state = 2;
    } else if (state == 2) {
      maxDef(U3hor, U1ver);
      minDef(U6hor, U4ver);
      maxDef(U9hor, U7ver);
      maxDef(U10hor, U12ver);
      minDef(U15hor, U13ver);
      maxDef(U18hor, U16ver);
      state = 3;
    } else if (state == 3) {
      defDef(U3hor, U1ver);
      defMin(U6hor, U4ver);
      defDef(U9hor, U7ver);
      defMin(U10hor, U12ver);
      defDef(U15hor, U13ver);
      defMin(U18hor, U16ver);
      state = 4;
    } else {
      minDef(U3hor, U1ver);
      maxDef(U6hor, U4ver);
      minDef(U9hor, U7ver);
      minDef(U10hor, U12ver);
      maxDef(U15hor, U13ver);
      minDef(U18hor, U16ver);
      state = 1;
    }
    delay(300);
  } else if (count >= 23) {
    Serial.println("backward");
    if (action != 4) {
      action = 4;
      state = 1;
    }
    if (state == 1) {
      defMin(U3hor, U1ver);
      defDef(U6hor, U4ver);
      defMin(U9hor, U7ver);
      defDef(U10hor, U12ver);
      defMin(U15hor, U13ver);
      defDef(U18hor, U16ver);
      state = 2;
    } else if (state == 2) {
      minDef(U3hor, U1ver);
      maxDef(U6hor, U4ver);
      minDef(U9hor, U7ver);
      minDef(U10hor, U12ver);
      maxDef(U15hor, U13ver);
      minDef(U18hor, U16ver);
      state = 3;
    } else if (state == 3) {
      defDef(U3hor, U1ver);
      defMin(U6hor, U4ver);
      defDef(U9hor, U7ver);
      defMin(U10hor, U12ver);
      defDef(U15hor, U13ver);
      defMin(U18hor, U16ver);
      state = 4;
    } else {
      maxDef(U3hor, U1ver);
      minDef(U6hor, U4ver);
      maxDef(U9hor, U7ver);
      maxDef(U10hor, U12ver);
      minDef(U15hor, U13ver);
      maxDef(U18hor, U16ver);
      state = 1;
    }
    delay(300);
  }
  lastButtonState = currentButtonState;
  delay(50);
}

// Motion States //
void defDef(Servo hor, Servo ver) {
  hor.write(def_deg);
  ver.write(def_deg);
}

void defMin(Servo hor, Servo ver) {
  hor.write(def_deg);
  ver.write(min_deg_ver);
}

void minDef(Servo hor, Servo ver) {
  hor.write(min_deg_hor);
  ver.write(def_deg);
}

void defMax(Servo hor, Servo ver) {
  hor.write(def_deg);
  ver.write(max_deg_ver);
}

void maxDef(Servo hor, Servo ver) {
  hor.write(max_deg_hor);
  ver.write(def_deg);
}
