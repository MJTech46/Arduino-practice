void setup() {
  Serial.begin(9600); // Start serial communication
}

void loop() {
  int num1 = 10;
  int num2 = 5;

  int sum = addNumbers(num1, num2);
  int difference = subtractNumbers(num1, num2);

  Serial.print("Sum: ");
  Serial.println(sum);

  Serial.print("Difference: ");
  Serial.println(difference);

  delay(2000); // Delay to prevent spamming the Serial Monitor
}

// Function for addition
int addNumbers(int a, int b) {
  return a + b;
}

// Function for subtraction
int subtractNumbers(int a, int b) {
  return a - b;
}