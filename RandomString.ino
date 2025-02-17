void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));  // Seed randomness with noise from an analog pin
  int length = 10;  // Change this to any desired length
  String randomString = generateRandomString(length);
  Serial.println(randomString);
}

void loop() {
  // Do nothing in loop
}

String generateRandomString(int length) {
  const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  int charsetSize = sizeof(charset) - 1;
  String result = "";
  
  for (int i = 0; i < length; i++) {
    result += charset[random(0, charsetSize)];
  }
  
  return result;
}
