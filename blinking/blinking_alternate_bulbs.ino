int LED_pins[] = {5, 16};
int blink_delay = 500;
int light_status = 1;

void setup() {
    pinMode(LED_pins[0], OUTPUT);
    pinMode(LED_pins[1], OUTPUT);
}

void loop() {
    digitalWrite(LED_pins[0], light_status);
    digitalWrite(LED_pins[1], !light_status);

    delay(blink_delay);

    light_status = !light_status;
}