const int buttonPin = 2;
const int led1 = 10;
const int led2 = 11;
const int led3 = 12;

unsigned long startTime;
unsigned long reactionTime;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  Serial.println("SYSTEM READY. Press button to start...");

  // Added delay(1) to let the simulator clock keep ticking
  while (digitalRead(buttonPin) == HIGH) {
    delay(1); 
  }

  Serial.println("Get Ready...");
  delay(1000); 

  digitalWrite(led1, HIGH);
  delay(1000);
  digitalWrite(led2, HIGH);
  delay(1000);
  digitalWrite(led3, HIGH);

  delay(random(1000, 3000));

  // THE F1 FALSE START TRAP
  if (digitalRead(buttonPin) == LOW) {
    Serial.println("====================");
    Serial.println("FALSE START PENALTY!");
    Serial.println("You clicked before the lights went out!");
    Serial.println("====================");
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(2000);
    return; // Restarts the loop instantly
  }

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);

  Serial.println("GO!!!");
  startTime = millis();

  // THE MAGIC FIX: delay(1) stops the Tinkercad stopwatch from freezing
  while (digitalRead(buttonPin) == HIGH) {
    delay(1); 
  }

  reactionTime = millis() - startTime;
  Serial.print("SCORE: ");
  Serial.print(reactionTime);
  Serial.println(" ms");
  Serial.println("====================");

  while (digitalRead(buttonPin) == LOW) {
    delay(1);
  }
  delay(2000); 
}