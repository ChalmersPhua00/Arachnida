# Arachnida
A 2-DOF Hexapod Robot.

___________________________________________________________________________________________________________________________________________________________

Project by: Chalmers Phua (https://github.com/ChalmersPhua00) and Enkhbold Ganbold (https://github.com/enkhbold470)

<sub>PCB designed by: Enkhbold Ganbold</sub>

<sub>Code programmed by: Chalmers Phua</sub>

___________________________________________________________________________________________________________________________________________________________

Electronics used
- MG90S servos (12 pcs)
- Songhe Mega 2560 Pro
- Ovonic 11.1V 2200mAh 50C lipo battery

___________________________________________________________________________________________________________________________________________________________

Button Movement Control
- integratedButtonMovementControl.ino uses one button to execute calibration.ino, rotateLeft.ino, rotateRight.ino, forward.ino, and backward.ino.
- Hexapod switches movement modes depending on how long the user holds the button.

https://user-images.githubusercontent.com/53986637/181388634-42fe824a-87f0-4002-813f-35d35019bf94.MOV

___________________________________________________________________________________________________________________________________________________________

Button Movement Control V2
- integratedButtonMovementControlV2.ino uses five buttons to execute calibration.ino, rotateLeftV2.ino, rotateRightV2.ino, forwardV2.ino, and backwardV2.ino.
- You may encounter voltage problem using Button Movement Control, Button Movement Control V2 uses map() to control the speed of the servos, therefore, it gives the hexapod a smoother motion.

https://user-images.githubusercontent.com/53986637/181388643-231edbd1-ac90-47c9-876b-5665772011f0.MOV

___________________________________________________________________________________________________________________________________________________________

PCB
- In PCB Components Order.png you will find the electronic components needed to solder on the PCB, you can buy them on https://www.lcsc.com/.
- Optional: Bluetooth module, ultrasonic sensor, ultrasonic sensor's servo.

![1](https://user-images.githubusercontent.com/107158272/181363161-c011a446-eda5-4864-9d76-7eab0f309747.jpeg)
![2](https://user-images.githubusercontent.com/107158272/181366368-e33a59ef-ca26-4ae7-96d1-578101002fe5.jpeg)
