#define RACKPOS 2
#define RACKNEG 3
#define RACKEN 9

#define KNIFEPOS 4
#define KNIFENEG 5
#define KNIFEEN 10

#define XPIN A2
#define YPIN A1

int xValue;
int yValue;

int tol = 3;

void setup() {
  Serial.begin(9600);

  pinMode(RACKPOS, OUTPUT);
  pinMode(RACKNEG, OUTPUT);

  pinMode(KNIFEPOS, OUTPUT);
  pinMode(KNIFENEG, OUTPUT);
}

void loop() {
  xValue = map(analogRead(XPIN), 0, 1024, -5, 5);
  yValue = map(analogRead(YPIN), 0, 1024, 5, -5);

  analogWrite(RACKEN, 255);
  analogWrite(KNIFEEN, 270);

  if (xValue >= tol) {
    digitalWrite(RACKPOS, HIGH);
    digitalWrite(RACKNEG, LOW);
    Serial.println(xValue);
  } else if (xValue <= -tol) {
    digitalWrite(RACKPOS, LOW);
    digitalWrite(RACKNEG, HIGH);
    Serial.println(xValue);
  } else {
    digitalWrite(RACKPOS, LOW);
    digitalWrite(RACKNEG, LOW);
  }

  if (yValue >= tol) {
    digitalWrite(KNIFEPOS, HIGH);
    digitalWrite(KNIFENEG, LOW);
    Serial.println(yValue);
  } else if (yValue <= -tol) {
    digitalWrite(KNIFEPOS, LOW);
    digitalWrite(KNIFENEG, HIGH);
    Serial.println(yValue);
  } else {
    digitalWrite(KNIFEPOS, LOW);
    digitalWrite(KNIFENEG, LOW);
  }

}
