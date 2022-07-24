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

int deg = 90;

void setup() {
  U3hor.attach(24);
  U3hor.write(deg);
  U1ver.attach(22);
  U1ver.write(deg);
  U6hor.attach(30);
  U6hor.write(deg);
  U4ver.attach(28);
  U4ver.write(deg);
  U9hor.attach(33);
  U9hor.write(deg);
  U7ver.attach(31);
  U7ver.write(deg);
  U10hor.attach(39);
  U10hor.write(deg);
  U12ver.attach(37);
  U12ver.write(deg);
  U15hor.attach(42);
  U15hor.write(deg);
  U13ver.attach(40);
  U13ver.write(deg);
  U18hor.attach(43);
  U18hor.write(deg);
  U16ver.attach(45);
  U16ver.write(deg);
}

void loop() {
}
