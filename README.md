# Arachnida-Mark-1.0
A 2-DOF Hexapod Robot.

___________________________________________________________________________________________________________________________________________________________

Project by: Chalmers Phua (https://github.com/ChalmersPhua00) and Enkhbold Ganbold (https://github.com/enkhbold470)

<sub>PCB designed by: Enkhbold Ganbold</sub>

<sub>Code programmed by: Chalmers Phua</sub>

<sub>Hexapod body parts 3D printed from: Nuttapon Poncharernpong (https://www.thingiverse.com/thing:1021540)</sub>

<sub>Hexapod buzzer code integrated from: Robson Couto (https://github.com/robsoncouto/arduino-songs)</sub>

___________________________________________________________________________________________________________________________________________________________

Electronics used
- MG90S servos (12 pcs)
- Songhe Mega 2560 Pro
- Ovonic 11.1V 2200mAh 50C lipo battery

___________________________________________________________________________________________________________________________________________________________

Button Movement Control
- integratedButtonMovementControl.ino uses buttonMovementControl.ino to execute calibration.ino, rotateLeft.ino, rotateRight.ino, forward.ino, and backward.ino.
- Hexapod switches movement modes depending on how long the user holds the button.
