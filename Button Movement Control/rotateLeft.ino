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

void setup() {
  int tempo = 120;
  int buzzer = 53;
  int melody[] = {1397, 8, 1175, 8, 1319, 8, 1047, 8};  
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

void maxDef(Servo hor, Servo ver) {
  hor.write(max_deg_hor);
  ver.write(def_deg);
}
