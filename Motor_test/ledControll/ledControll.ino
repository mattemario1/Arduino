
const int ledPin = 3;
const int potentiometerPin = A0;
int analogValue = 0;

void setup()
{
    Serial.begin(9600);
    // pinMode(ledPin, INPUT);
}

void loop()
{
    analogValue = analogRead(potentiometerPin);
    analogValue = map(analogValue, 0, 660, 0, 255);
    analogWrite(ledPin, analogValue);

    Serial.println(analogValue);
}
