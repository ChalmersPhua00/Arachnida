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
double servoSpeed = 500;
int progress = 0;
int state = 2;
int action = 0;

const int  buttonPin2 = 2;
const int  buttonPin4 = 4;
const int  buttonPin6 = 6;
const int  buttonPin8 = 8;
const int  buttonPin10 = 10;

void setup() {
  int tempo = 120;
  int buzzer = 53;
  int melody[] = {};  
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
    tone(buzzer, melody[thisNote], noteDuration*0.9);
    delay(noteDuration);
    noTone(buzzer);
  }
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);
  pinMode(buttonPin8, INPUT_PULLUP);
  pinMode(buttonPin10, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonPin2) == LOW || action == 0) { // Calibrate
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
  }
  if (digitalRead(buttonPin4) == LOW || action == 1) { // Rotate Left
    if (action != 1) {
      action = 1;
      state = 2;
      progress = 0;
    }
    if (state == 1) {
      progress += 2;
      if (progress <= servoSpeed) {
        defMin(progress, U3hor, U1ver, def_deg, def_deg);
        defDef(progress, U6hor, U4ver, def_deg, def_deg);
        defMin(progress, U9hor, U7ver, def_deg, def_deg);
        defDef(progress, U10hor, U12ver, def_deg, def_deg);
        defMin(progress, U15hor, U13ver, def_deg, def_deg);
        defDef(progress, U18hor, U16ver, def_deg, def_deg);
      } else {
        state = 2;
        progress = 0;
      }
    } else if (state == 2) {
      progress += 2;
      if (progress <= servoSpeed) {
        maxDef(progress, U3hor, U1ver, def_deg, min_deg_ver);
        minDef(progress, U6hor, U4ver, def_deg, def_deg);
        maxDef(progress, U9hor, U7ver, def_deg, min_deg_ver);
        minDef(progress, U10hor, U12ver, def_deg, def_deg);
        maxDef(progress, U15hor, U13ver, def_deg, min_deg_ver);
        minDef(progress, U18hor, U16ver, def_deg, def_deg);
      } else {
        state = 3;
        progress = 0;
      }
    } else {
      progress += 2;
      if (progress <= servoSpeed) {
        defDef(progress, U3hor, U1ver, max_deg_hor, def_deg);
        defDef(progress, U6hor, U4ver, min_deg_hor, def_deg);
        defDef(progress, U9hor, U7ver, max_deg_hor, def_deg);
        defDef(progress, U10hor, U12ver, min_deg_hor, def_deg);
        defDef(progress, U15hor, U13ver, max_deg_hor, def_deg);
        defDef(progress, U18hor, U16ver, min_deg_hor, def_deg);
      } else {
        state = 1;
        progress = 0;
      }
    }
  }
  if (digitalRead(buttonPin6) == LOW || action == 2) { // Rotate Right
    if (action != 2) {
      action = 2;
      state = 2;
      progress = 0;
    }
    if (state == 1) {
      progress += 2;
      if (progress <= servoSpeed) {
        defMin(progress, U3hor, U1ver, def_deg, def_deg);
        defDef(progress, U6hor, U4ver, def_deg, def_deg);
        defMin(progress, U9hor, U7ver, def_deg, def_deg);
        defDef(progress, U10hor, U12ver, def_deg, def_deg);
        defMin(progress, U15hor, U13ver, def_deg, def_deg);
        defDef(progress, U18hor, U16ver, def_deg, def_deg);
      } else {
        state = 2;
        progress = 0;
      }
    } else if (state == 2) {
      progress += 2;
      if (progress <= servoSpeed) {
        minDef(progress, U3hor, U1ver, def_deg, min_deg_ver);
        maxDef(progress, U6hor, U4ver, def_deg, def_deg);
        minDef(progress, U9hor, U7ver, def_deg, min_deg_ver);
        maxDef(progress, U10hor, U12ver, def_deg, def_deg);
        minDef(progress, U15hor, U13ver, def_deg, min_deg_ver);
        maxDef(progress, U18hor, U16ver, def_deg, def_deg);
      } else {
        state = 3;
        progress = 0;
      }
    } else {
      progress += 2;
      if (progress <= servoSpeed) {
        defDef(progress, U3hor, U1ver, min_deg_hor, def_deg);
        defDef(progress, U6hor, U4ver, max_deg_hor, def_deg);
        defDef(progress, U9hor, U7ver, min_deg_hor, def_deg);
        defDef(progress, U10hor, U12ver, max_deg_hor, def_deg);
        defDef(progress, U15hor, U13ver, min_deg_hor, def_deg);
        defDef(progress, U18hor, U16ver, max_deg_hor, def_deg);
      } else {
        state = 1;
        progress = 0;
      }
    }
  }
  if (digitalRead(buttonPin8) == LOW || action == 3) { // Forward
    if (action != 3) {
      action = 3;
      state = 2;
      progress = 0;
    }
    if (state == 1) {
      progress += 2;
      if (progress <= servoSpeed) {
        defMin(progress, U3hor, U1ver, min_deg_hor, def_deg);
        defDef(progress, U6hor, U4ver, max_deg_hor, def_deg);
        defMin(progress, U9hor, U7ver, min_deg_hor, def_deg);
        defDef(progress, U10hor, U12ver, min_deg_hor, def_deg);
        defMin(progress, U15hor, U13ver, max_deg_hor, def_deg);
        defDef(progress, U18hor, U16ver, min_deg_hor, def_deg);
      } else {
        state = 2;
        progress = 0;
      }
    } else if (state == 2) {
      progress += 2;
      if (progress <= servoSpeed) {
        maxDef(progress, U3hor, U1ver, def_deg, min_deg_ver);
        minDef(progress, U6hor, U4ver, def_deg, def_deg);
        maxDef(progress, U9hor, U7ver, def_deg, min_deg_ver);
        maxDef(progress, U10hor, U12ver, def_deg, def_deg);
        minDef(progress, U15hor, U13ver, def_deg, min_deg_ver);
        maxDef(progress, U18hor, U16ver, def_deg, def_deg);
      } else {
        state = 3;
        progress = 0;
      }
    } else if (state == 3) {
      progress += 2;
      if (progress <= servoSpeed) {
        defDef(progress, U3hor, U1ver, max_deg_hor, def_deg);
        defMin(progress, U6hor, U4ver, min_deg_hor, def_deg);
        defDef(progress, U9hor, U7ver, max_deg_hor, def_deg);
        defMin(progress, U10hor, U12ver, max_deg_hor, def_deg);
        defDef(progress, U15hor, U13ver, min_deg_hor, def_deg);
        defMin(progress, U18hor, U16ver, max_deg_hor, def_deg);
      } else {
        state = 4;
        progress = 0;
      }
    } else {
      progress += 2;
      if (progress <= servoSpeed) {
        minDef(progress, U3hor, U1ver, def_deg, def_deg);
        maxDef(progress, U6hor, U4ver, def_deg, min_deg_ver);
        minDef(progress, U9hor, U7ver, def_deg, def_deg);
        minDef(progress, U10hor, U12ver, def_deg, min_deg_ver);
        maxDef(progress, U15hor, U13ver, def_deg, def_deg);
        minDef(progress, U18hor, U16ver, def_deg, min_deg_ver);
      } else {
        state = 1;
        progress = 0;
      }
    }
  }
  if (digitalRead(buttonPin10) == LOW || action == 4) { // Backward
    if (action != 4) {
      action = 4;
      state = 2;
      progress = 0;
    }
    if (state == 1) {
      progress += 2;
      if (progress <= servoSpeed) {
        defMin(progress, U3hor, U1ver, max_deg_hor, def_deg);
        defDef(progress, U6hor, U4ver, min_deg_hor, def_deg);
        defMin(progress, U9hor, U7ver, max_deg_hor, def_deg);
        defDef(progress, U10hor, U12ver, max_deg_hor, def_deg);
        defMin(progress, U15hor, U13ver, min_deg_hor, def_deg);
        defDef(progress, U18hor, U16ver, max_deg_hor, def_deg);
      } else {
        state = 2;
        progress = 0;
      }
    } else if (state == 2) {
      progress += 2;
      if (progress <= servoSpeed) {
        minDef(progress, U3hor, U1ver, def_deg, min_deg_ver);
        maxDef(progress, U6hor, U4ver, def_deg, def_deg);
        minDef(progress, U9hor, U7ver, def_deg, min_deg_ver);
        minDef(progress, U10hor, U12ver, def_deg, def_deg);
        maxDef(progress, U15hor, U13ver, def_deg, min_deg_ver);
        minDef(progress, U18hor, U16ver, def_deg, def_deg);
      } else {
        state = 3;
        progress = 0;
      }
    } else if (state == 3) {
      progress += 2;
      if (progress <= servoSpeed) {
        defDef(progress, U3hor, U1ver, min_deg_hor, def_deg);
        defMin(progress, U6hor, U4ver, max_deg_hor, def_deg);
        defDef(progress, U9hor, U7ver, min_deg_hor, def_deg);
        defMin(progress, U10hor, U12ver, min_deg_hor, def_deg);
        defDef(progress, U15hor, U13ver, max_deg_hor, def_deg);
        defMin(progress, U18hor, U16ver, min_deg_hor, def_deg);
      } else {
        state = 4;
        progress = 0;
      }
    } else {
      progress += 2;
      if (progress <= servoSpeed) {
        maxDef(progress, U3hor, U1ver, def_deg, def_deg);
        minDef(progress, U6hor, U4ver, def_deg, min_deg_ver);
        maxDef(progress, U9hor, U7ver, def_deg, def_deg);
        maxDef(progress, U10hor, U12ver, def_deg, min_deg_ver);
        minDef(progress, U15hor, U13ver, def_deg, def_deg);
        maxDef(progress, U18hor, U16ver, def_deg, min_deg_ver);
      } else {
        state = 1;
        progress = 0;
      }
    }
  }
}

// Motion States //
void defDef(int progress, Servo hor, Servo ver, int start_deg_hor, int start_deg_ver) {
  long horAngle = map(progress, 0, servoSpeed, start_deg_hor, def_deg);
  long verAngle = map(progress, 0, servoSpeed, start_deg_ver, def_deg);
  hor.write(horAngle);
  ver.write(verAngle);
}

void defMin(int progress, Servo hor, Servo ver, int start_deg_hor, int start_deg_ver) {
  long horAngle = map(progress, 0, servoSpeed, start_deg_hor, def_deg);
  long verAngle = map(progress, 0, servoSpeed, start_deg_ver, min_deg_ver);
  hor.write(horAngle);
  ver.write(verAngle);
}

void minDef(int progress, Servo hor, Servo ver, int start_deg_hor, int start_deg_ver) {
  long horAngle = map(progress, 0, servoSpeed, start_deg_hor, min_deg_hor);
  long verAngle = map(progress, 0, servoSpeed, start_deg_ver, def_deg);
  hor.write(horAngle);
  ver.write(verAngle);
}

void maxDef(int progress, Servo hor, Servo ver, int start_deg_hor, int start_deg_ver) {
  long horAngle = map(progress, 0, servoSpeed, start_deg_hor, max_deg_hor);
  long verAngle = map(progress, 0, servoSpeed, start_deg_ver, def_deg);
  hor.write(horAngle);
  ver.write(verAngle);
}
