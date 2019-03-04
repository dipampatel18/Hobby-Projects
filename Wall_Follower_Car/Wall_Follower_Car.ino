
int forward_pin = 5;
int reverse_pin = 4;
int right_pin = 3;
int left_pin = 2;
int output = A0;
int ground = A1;
int vcc = A2;

void setup() {
  pinMode(forward_pin, OUTPUT);
  pinMode(reverse_pin, OUTPUT);
  pinMode(right_pin, OUTPUT);
  pinMode(left_pin, OUTPUT);

  pinMode(output, INPUT);
  pinMode(ground, OUTPUT);
  pinMode(vcc, OUTPUT);
  
  digitalWrite(A2, HIGH);
  digitalWrite(A1, LOW);
  Serial.begin(115200);
}

void loop() {
  delay(100);
  
  if (analogRead(A0) < 200) {
    digitalWrite(forward_pin, LOW);
    digitalWrite(reverse_pin, LOW);
    digitalWrite(right_pin, HIGH);
    digitalWrite(left_pin, LOW);
    Serial.println("Wall Detected");
  }
  
  else {
    digitalWrite(forward_pin, LOW);
    digitalWrite(reverse_pin, LOW);
    digitalWrite(right_pin, LOW);
    digitalWrite(left_pin, HIGH);
    Serial.println("Driving Straight / Away from the Wall");
  }
 
}
