int buttonPin = 1;
int ledPin = 16;
int buttonState = 0;

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
}

void loop() {
    buttonState = digitalRead(buttonPin);
    digitalWrite(ledPin, buttonState);
}