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

void setup() {
  int tempo = 120;
  int buzzer = 53;
  int melody[] = {1047, 8, 1319, 8, 1568, 8};  
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
  
  U3hor.attach(24);
  U1ver.attach(22);
  U6hor.attach(30);
  U4ver.attach(28);
  U9hor.attach(33);
  U7ver.attach(31);
  U10hor.attach(39);
  U12ver.attach(37);
  U15hor.attach(42);
  U13ver.attach(40);
  U18hor.attach(43);
  U16ver.attach(45);
}

void loop() {
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
