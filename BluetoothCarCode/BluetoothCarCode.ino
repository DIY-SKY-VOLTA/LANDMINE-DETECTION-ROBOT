
// Here some main variables are not changed, the original variable actually we have to put are denoted below.
//front light on/off - Camera Tilt Upward
//Horn On/off         -      Camera Tilt Downwards
//Back Lifght On/off  -      Bomb Pointer drops a pointer and reset to its intial position
//Forward button      -      Robot moves forward
//Backward Button     -      Robot moves backward
//Left button         -      Robot moves left direction
//Right button        -      Robot moves Right direction
//Parking Lights      -      Empty (spare)



#include <Servo.h>
unsigned long previousMillis = 0;  // Stores the time when the servo started moving
const int rotationDuration = 3000; // Duration of rotation in milliseconds


Servo s1;
Servo s2;// CAM Servo 

int i = 0;
int count = 10;

#define in1 3
#define in2 5
#define in3 6
#define in4 11
#define HORN 7
#define LEDP 4

int command; // Int to store app command state.
int Speed = 204; // 0 - 255.
int Speedsec;

int buttonState = 0;
int lastButtonState = 0;
int Turnradius = 0; // Set the radius of a turn, 0 - 255 Note: the robot will malfunction if this is higher than int Speed.
int brakeTime = 45;
int brkonoff = 1; // 1 for the electronic braking system, 0 for normal.

void setup() {
  s1.attach(10);
  s2.attach(9);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(HORN, OUTPUT);
  pinMode(LEDP, OUTPUT);

  Serial.begin(9600); // Set the baud rate to your Bluetooth module.
}

void loop() {
  unsigned long currentMillis = millis();  // Get the current time

  // Check if it's time to stop rotating
  if (currentMillis - previousMillis < rotationDuration) {
    // Rotate the CAM servo 
    s2.write(0);
    delay(1100); 
    s2.write(120);
    delay(1100); 
    s2.write(60); // Initial Position
    delay(1100);
     s1.write(180); // Initial Position
    delay(1100); // Replace CAM SERVO_ANGLE with the desired angle (30-120)
  }
  if (Serial.available() > 0) {
    command = Serial.read();
    Stop(); // Initialize with motors stopped.
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'G':
        forwardleft();
        break;
      case 'I':
        forwardright();
        break;
      case 'H':
        backleft();
        break;
      case 'J':
        backright();
        break;
      case 'W':
        frontledon();
        break;
      case 'w':
        frontledoff();
        break;
      case 'U':
        backledon();
        break;
      case 'u':
        backledoff();
        break;
      case 'V':
        hornon();
        break;
     // case 'v':
       // hornoff();
       // break;
     // case 'X':
       // parkledon();
      //  break;
     // case 'x':
     //   parkledoff();
       // break;
      case '0':
        Speed = 100;
        break;
      case '1':
        Speed = 140;
        break;
      case '2':
        Speed = 153;
        break;
      case '3':
        Speed = 165;
        break;
      case '4':
        Speed = 178;
        break;
      case '5':
        Speed = 191;
        break;
      case '6':
        Speed = 204;
        break;
      case '7':
        Speed = 216;
        break;
      case '8':
        Speed = 229;
        break;
      case '9':
        Speed = 242;
        break;
      case 'q':
        Speed = 255;
        break;
    }

    Speedsec = Turnradius;
    /*if (brkonoff == 1) {
      brakeOn();
    } else {
      brakeOff();
    }*/
  }
}

void forward() {
  analogWrite(in1, Speed);
  analogWrite(in3, Speed);
}

void back() {
  analogWrite(in2, Speed);
  analogWrite(in4, Speed);
}

void left() {
  analogWrite(in3, Speed);
  analogWrite(in2, Speed);
}

void right() {
  analogWrite(in4, Speed);
  analogWrite(in1, Speed);
}

void forwardleft() {
  analogWrite(in1, Speedsec);
  analogWrite(in3, Speed);
}

void forwardright() {
  analogWrite(in1, Speed);
  analogWrite(in3, Speedsec);
}

void backright() {
  analogWrite(in2, Speed);
  analogWrite(in4, Speedsec);
}

void backleft() {
  analogWrite(in2, Speedsec);
  analogWrite(in4, Speed);
}

void Stop() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
}

void frontledon() { // Turn Front led on or off
 
  count++;
  Serial.println(count);
  switch (count) {
      case 10:
      s2.write(80);
      break;
    case 9:
      s2.write(70);
      break;
    case 8:
      s2.write(60);
      break;
    case 7:
      s2.write(50);
      break;
    case 6:
      s2.write(40);
      break;
    case 5:
      s2.write(30);
      break;
    case 4:
      s2.write(20);
      break;
    case 3:
      s2.write(10);
      break;
    case 2:
      s2.write(0);
      break;
    case 11:
      s2.write(90);
      break;
    case 12:
      s2.write(95);
      break;
    case 13:
      s2.write(100);
      break;
    case 14:
      s2.write(105);
      break;
    case 15:
      s2.write(110);
      break;
    case 16:
      s2.write(115);
      break;
    case 17:
      s2.write(120);
      break;
    //case 18:
     // s2.write(125);
      //break;
    //case 19:
     // s2.write(130);
     // break;
   // case 20:
     // s2.write(135);
      //break;
    //case 21:
     // s2.write(140);
     // break;
   // case 22:
     // s2.write(145);
     // break;
   // case 23:
     // s2.write(150);
    //  break;
   // case 24:
     // s2.write(155);
     // break;
   // case 25:
      //s2.write(160);
     // break;
   // case 26:
     // s2.write(165);
      //break;
    //case 27:
    //  s2.write(170);
     // break;
   // case 28:
    //  s2.write(175);
   //   break;
   // case 29:
    //  s2.write(180);
     // break;
  }
}

void frontledoff() { // Turn Front led off
  
  }


void backledon() { // Turn Back led on
  for (i = 180; i >= 0; i -= 1) {
    s1.write(i);
    delay(15);
  }
}

void backledoff() { // Turn Back led off
  for (i = 0; i <= 180; i += 1) {
    s1.write(i);
    delay(1);
  }
}

void hornon() {
  count--;
  Serial.println(count);
  switch (count) {
    case 11:
      s2.write(90);
      break;
    case 10:
      s2.write(80);
      break;
    case 9:
      s2.write(70);
      break;
    case 8:
      s2.write(60);
      break;
    case 7:
      s2.write(50);
      break;
    case 6:
      s2.write(40);
      break;
    case 5:
      s2.write(30);
      break;
    case 4:
      s2.write(20);
      break;
    case 3:
      s2.write(10);
      break;
    case 2:
      s2.write(0);
      break;
    case 12:
      s2.write(95);
      break;
    case 13:
      s2.write(100);
      break;
    case 14:
      s2.write(105);
      break;
    case 15:
      s2.write(110);
      break;
    case 16:
      s2.write(115);
      break;
    case 17:
      s2.write(120);
      break;
    //case 18:
      //s2.write(125);
     // break;
    //case 19:
      //s2.write(130);
      //break;
    //case 20:
     // s2.write(135);
      //break;
    //case 21:
    //  s2.write(140);
     // break;
    //case 22:
    //  s2.write(145);
    //  break;
   // case 23:
    //  s2.write(150);
    //  break;
    //case 24:
    //  s2.write(155);
     // break;
    //case 25:
     // s2.write(160);
    //  break;
    //case 26:
     // s2.write(165);
    //  break;
    //case 27:
     // s2.write(170);
     // break;
   // case 28:
    //  s2.write(175);
     // break;
    //case 29:
    //  s2.write(180);
     // break;
}
}

//void hornoff() {
  
//}

/*void parkledon() {
 
}

void parkledoff() {
  
}

void brakeOn() {




buttonState = command;





if (buttonState != lastButtonState) {





if (buttonState == 'S') {


if (lastButtonState != buttonState) {


digitalWrite(in1, HIGH);


digitalWrite(in2, HIGH);


digitalWrite(in3, HIGH);


digitalWrite(in4, HIGH);


delay(brakeTime);


Stop();


}


}



lastButtonState = buttonState;


}


}


  void brakeOff() {

  }*/