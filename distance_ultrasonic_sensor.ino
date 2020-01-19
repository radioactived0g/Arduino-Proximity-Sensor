const int pingPin = 7;
const int echoPin = 8;

const int redLed = 4;
const int yellowLed = 3;
const int greenLed = 2;

// constants won't change. Used here to set a pin number:
const int ledPin =  LED_BUILTIN;// the number of the LED pin

long avg = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(ledPin, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  digitalWrite(ledPin, HIGH);
  delay (500);
  digitalWrite(ledPin, LOW);
  delay (500);
  digitalWrite(redLed, HIGH);
  digitalWrite(ledPin, HIGH);
  delay (500);
  digitalWrite(yellowLed, HIGH);
  digitalWrite(ledPin, LOW);
  delay (500);
  digitalWrite(greenLed, HIGH);
  digitalWrite(ledPin, HIGH);
  delay (500);
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, inches, cm;

 // set the LED with the ledState of the variable:
  digitalWrite(ledPin, LOW);

  digitalWrite(pingPin, LOW);
  delayMicroseconds(10);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in. ");
  Serial.write('\t');
  Serial.print(cm);
  Serial.print("cm. ");
  Serial.write('\t');
  Serial.write("avg: ");
  Serial.print(avg);
  Serial.print("cm.");
  Serial.write('\n');

  avg = (avg + cm)/2;
  
  if ((avg > 70) & (avg <= 120))  
  {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, HIGH);
  }

  else if ((avg > 30) && (avg <= 70))  
  {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, LOW);
  }

  else if ((avg > 0) && (avg <= 30))  
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
  }

  else if ((avg == 0) || (avg > 100))  
  {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
  }

  delay (200);
  digitalWrite(ledPin, HIGH);
}

long microsecondsToInches(long microseconds)
{
    return microseconds / 74 /2;
}

long microsecondsToCentimeters(long microseconds)
{
    return microseconds / 29.1 /2;
}
