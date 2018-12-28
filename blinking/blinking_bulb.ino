int LED_pin = 16;
int blink_delay = 500;
int light_status = true;

void setup() {
    pinMode(LED_pin, OUTPUT);
}

void loop() {
    digitalWrite(LED_pin, light_status);

    delay(blink_delay);

    light_status = !light_status;
}