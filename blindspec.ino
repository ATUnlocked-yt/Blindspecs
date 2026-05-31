const int trigPin = 10;
const int echoPin = 8;

const int buzzerPin = 9;
const int ledPin = 13;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);

  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= 20) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 2500);
    delay(100);
  }
  else if (distance <= 50) {
    digitalWrite(ledPin, HIGH);

    tone(buzzerPin, 1500);
    delay(200);

    noTone(buzzerPin);
    delay(200);
  }
  else if (distance <= 100) {
    digitalWrite(ledPin, HIGH);

    tone(buzzerPin, 1000);
    delay(500);

    noTone(buzzerPin);
    delay(500);
  }
  else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }
}