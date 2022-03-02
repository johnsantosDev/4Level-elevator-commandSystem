
int i = 1; // the value represents where elevator stay ( fisrt time elevator start in the first floor
int btn4 = 8; // represents the 4 th floor
int btn3 = 7; //             2 nd floor
int btn2 = 6; //                3 th floor
int btn1 = 5; //               1 st floor

int buttonState = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;


int motorPin1 = 10;
int motorPin2 = 11;
int motorPin3 = 12;
int motorPin4 = 13;
const int PIN_SEGMENT_A = 14;
const int PIN_SEGMENT_B = 15;
const int PIN_SEGMENT_C = 16;
const int PIN_SEGMENT_D = 17;
const int PIN_SEGMENT_E = 18;
const int PIN_SEGMENT_F = 19;
const int PIN_SEGMENT_G = 20;
const int PIN_SEGMENT_DP = 21;
int elevatorpos = 1;
const bool butt1 = 0;
const bool butt2 = 0;
const bool butt3 = 0;
const bool butt4 = 0;

int myposition = 0;
int caller = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  int delayTime = 50;


  Serial.begin(9600);

  pinMode(btn4, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn1, INPUT);

  Serial.begin(9600);
  pinMode(PIN_SEGMENT_A, OUTPUT);
  digitalWrite(PIN_SEGMENT_A, LOW);
  pinMode(PIN_SEGMENT_B, OUTPUT);
  digitalWrite(PIN_SEGMENT_B, LOW);
  pinMode(PIN_SEGMENT_C, OUTPUT);
  digitalWrite(PIN_SEGMENT_C, LOW);
  pinMode(PIN_SEGMENT_D, OUTPUT);
  digitalWrite(PIN_SEGMENT_D, LOW);
  pinMode(PIN_SEGMENT_E, OUTPUT);
  digitalWrite(PIN_SEGMENT_E, LOW);
  pinMode(PIN_SEGMENT_F, OUTPUT);
  digitalWrite(PIN_SEGMENT_F, LOW);
  pinMode(PIN_SEGMENT_G, OUTPUT);
  digitalWrite(PIN_SEGMENT_G, LOW);
  pinMode(PIN_SEGMENT_DP, OUTPUT);
  digitalWrite(PIN_SEGMENT_DP, LOW);
  show(elevatorpos);

}

void loop() {
  buttonState = digitalRead(btn1);
  buttonState2 = digitalRead(btn2);
  buttonState3 = digitalRead(btn3);
  buttonState4 = digitalRead(btn4);

  if (buttonState4 == HIGH) {
    caller = 4;
    for (int i = 0; i <= 4; i++) {
      if (elevatorpos == i) {
        drivePosition(caller, elevatorpos);
      }
    }
  }
  else if (buttonState3 == HIGH) {
    caller = 3;
    for (int i = 0; i <= 4; i++) {
      if (elevatorpos == i) {
        drivePosition(caller, elevatorpos);
      }
    }
  }
  else if (buttonState2 == HIGH) {
    caller = 2;
    for (int i = 0; i <= 4; i++) {
      if (elevatorpos == i) {
        drivePosition(caller, elevatorpos);
      }
    }
  }
  else if (buttonState == HIGH) {
    caller = 1;
    for (int i = 0; i <= 4; i++) {
      if (elevatorpos == i) {
        drivePosition(caller, elevatorpos);
      }
    }
  }
}

void drivePosition(int c, int p) {
  //fourth floor
  if (c == 4) {
    if (p < 4) {
      for (int i = p; i <= c; i++) {
        elevatorpos = i;
        show(elevatorpos);
        up();
      }
    }
    else if (c == 4 && p == 4) {
      show(4);
    }
  }
  //floor three
  else if (c == 3) {
    if (p < 3) {
      for (int i = p; i <= c; i++) {
        elevatorpos = i;
        show(elevatorpos);
        up();
      }
    }
    else if (p > 3) {
      show(4);
      down();
      show(3);
    }
    else {
      show(3);
    }
  }

  //floor two
  else if (c == 2) {
    if (p < 2) {
      for (int i = p; i <= c; i++) {
        elevatorpos = i;
        show(elevatorpos);
        up();
      }
    }
    else if (p > 2) {
      for (int i = p; i >= c; i--) {
        elevatorpos = i;
        show(elevatorpos);
        down();
      }
    }
    else {
      show(2);
    }
  }

  //floor one
  else if (c == 1) {
    if (p < 1) {
      for (int i = p; i >= c; i++) {
        elevatorpos = i;
        show(elevatorpos);
        up();
      }
    }
    else if (p > 1) {
      for (int i = p; i >= c; i--) {
        elevatorpos = i;
        show(elevatorpos);
        down();
      }
    }
    else {
      show(1);
    }
  }

  //floor 0
  else if (c == 0) {
    if (p <= 0) {
      show(0);
    }
    else if (p > 1) {
      for (int i = p; i >= c; i--) {
        elevatorpos = i;
        show(elevatorpos);
        down();
      }
    }
  }
}

void up() { // each floor distance where it works to up
  for (int b = 0; b < 300; b++) {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(3);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(3);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(3);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(3);
  }
}
void down() { // each floor distance where it works to down
  for (int a = 0; a < 300; a++) {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(3);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(3);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(3);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(3);

  }
}

void show(int position) {
  if (position == 0) {
    digitalWrite(PIN_SEGMENT_A, HIGH);
    digitalWrite(PIN_SEGMENT_B, HIGH);
    digitalWrite(PIN_SEGMENT_C, HIGH);
    digitalWrite(PIN_SEGMENT_D, HIGH);
    digitalWrite(PIN_SEGMENT_E, HIGH);
    digitalWrite(PIN_SEGMENT_F, HIGH);
    digitalWrite(PIN_SEGMENT_G, LOW);
  }
  else if (position == 1) {
    digitalWrite(PIN_SEGMENT_A, LOW);
    digitalWrite(PIN_SEGMENT_B, HIGH);
    digitalWrite(PIN_SEGMENT_C, HIGH);
    digitalWrite(PIN_SEGMENT_D, LOW);
    digitalWrite(PIN_SEGMENT_E, LOW);
    digitalWrite(PIN_SEGMENT_F, LOW);
    digitalWrite(PIN_SEGMENT_G, LOW);
  }
  else if (position == 2) {
    digitalWrite(PIN_SEGMENT_A, HIGH);
    digitalWrite(PIN_SEGMENT_B, HIGH);
    digitalWrite(PIN_SEGMENT_C, LOW);
    digitalWrite(PIN_SEGMENT_D, HIGH);
    digitalWrite(PIN_SEGMENT_E, HIGH);
    digitalWrite(PIN_SEGMENT_F, LOW);
    digitalWrite(PIN_SEGMENT_G, HIGH);
  }
  else if (position == 3) {
    digitalWrite(PIN_SEGMENT_A, HIGH);
    digitalWrite(PIN_SEGMENT_B, HIGH);
    digitalWrite(PIN_SEGMENT_C, HIGH);
    digitalWrite(PIN_SEGMENT_D, HIGH);
    digitalWrite(PIN_SEGMENT_E, LOW);
    digitalWrite(PIN_SEGMENT_F, LOW);
    digitalWrite(PIN_SEGMENT_G, HIGH);
  }
  else if (position == 4) {
    digitalWrite(PIN_SEGMENT_A, LOW);
    digitalWrite(PIN_SEGMENT_B, HIGH);
    digitalWrite(PIN_SEGMENT_C, HIGH);
    digitalWrite(PIN_SEGMENT_D, LOW);
    digitalWrite(PIN_SEGMENT_E, LOW);
    digitalWrite(PIN_SEGMENT_F, HIGH);
    digitalWrite(PIN_SEGMENT_G, HIGH);
  }
}
