int forward_pin = 5;
int reverse_pin = 4;
int right_pin = 3;
int left_pin = 2;

char incomingByte = ' ';

void setup() {
  
  pinMode(forward_pin, OUTPUT);
  pinMode(reverse_pin, OUTPUT);
  pinMode(right_pin, OUTPUT);
  pinMode(left_pin, OUTPUT);
  Serial.begin(115200);
}

void forward_move() {
  Serial.println("Moving Forward");
  digitalWrite(forward_pin, HIGH);
  digitalWrite(reverse_pin, LOW);
  digitalWrite(right_pin, HIGH);
  digitalWrite(left_pin, HIGH);
}

void reverse_move() {
  Serial.println("Moving Reverse");
  digitalWrite(forward_pin, LOW);
  digitalWrite(reverse_pin, HIGH);
  digitalWrite(right_pin, HIGH);
  digitalWrite(left_pin, HIGH);
}

void forward_right_move() {    
  Serial.println("Moving Forward + Right");
  digitalWrite(forward_pin, LOW);
  digitalWrite(reverse_pin, LOW);
  digitalWrite(right_pin, HIGH);
  digitalWrite(left_pin, LOW);
}

void forward_left_move() {
  Serial.println("Moving Forward + Left");
  digitalWrite(forward_pin, LOW);
  digitalWrite(reverse_pin, LOW);
  digitalWrite(right_pin, LOW);
  digitalWrite(left_pin, HIGH);
}

void right_move() {
  Serial.println("Turning Right");
  digitalWrite(forward_pin, HIGH);
  digitalWrite(reverse_pin, HIGH);
  digitalWrite(right_pin, HIGH);
  digitalWrite(left_pin, LOW);  
}

void left_move() {
  Serial.println("Turning Left");
  digitalWrite(forward_pin, HIGH);
  digitalWrite(reverse_pin, HIGH);
  digitalWrite(right_pin, LOW);
  digitalWrite(left_pin, HIGH);  
}

void hold_move() {
  Serial.println("Stopping");
  digitalWrite(forward_pin, LOW);
  digitalWrite(reverse_pin, LOW);
  digitalWrite(right_pin, LOW);
  digitalWrite(left_pin, LOW);  
}

void loop() {
  
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    
    switch (incomingByte) {
      case 'w':
        forward_move();
        break;

      case 's':
        reverse_move();
        break;
        
      case 'd':
        forward_right_move();
        break;

      case 'a':
        forward_left_move();
        break;
        
      case 'c':
        right_move();
        break;
        
      case 'z':
        left_move();
        break;
        
      case 'x':
        hold_move();
        break;        
    }
    
  }
  
}
