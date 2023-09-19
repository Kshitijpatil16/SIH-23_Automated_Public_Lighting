
const int LDR_THRESHOLD = 700;
const int LED_MAX_INTENSITY = 255;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  // Initialize digital pins for IR sensors
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);

  // Initializing analog pin of LDR
  pinMode(A1, INPUT); // Declare A1 as an analog input
 
  // Initialize LED control pins as outputs
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  
  int LDRIN, IR1, IR2, IR3, IR4, power1, power2, power3, power4;
 
  LDRIN = analogRead(A1);
  IR1 = digitalRead(4);
  IR2 = digitalRead(5);
  IR3 = digitalRead(6);
  IR4 = digitalRead(7);
 
  Serial.print(LDRIN);
  Serial.print(",");
  Serial.print(power1);
  Serial.print(",");
  Serial.print(power2);
  Serial.print(",");
  Serial.print(power3);
  Serial.print(",");
  Serial.print(power4);
  Serial.print(",");


  if (LDRIN < LDR_THRESHOLD) {
    // Turn off all LEDs
      analogWrite(3, 0);
      analogWrite(9, 0);
      analogWrite(10, 0);
      analogWrite(11, 0);
      power1 = 0;
      power2 = 0;
      power3 = 0;
      power4 = 0;
   
  } else {
    // Control LEDs based on IR sensor and temperature readings
    controlLED3(3, 9, IR1, LDRIN, power1);
    controlLED(9, 10, IR2, temp2, power2);
    controlLED(10, 11, IR3, temp3, power3);
    controlLED(11, 3, IR4, temp4, power4);
  }
 
  delay(1000); // Wait for 1000 milliseconds
}

void controlLED(int pin1, int pin2, int irSensor, int temp, int power) {
  if (irSensor == 0) {
    analogWrite(pin1, 255);
    analogWrite(pin2, 255);
    power += 0.1089;
  }
  else {
    analogWrite(pin1, 15);
    analogWrite(pin2, 15);
    power += 0.0003;
  }
}
