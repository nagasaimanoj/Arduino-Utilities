// RGB LED Gaussian Wave Breathing LED

int led_pin = 16;

void setup()
{
    pinMode(led_pin, OUTPUT);
}

void loop()
{
    float pwm_val = 255.0 * (exp(-(pow(((1 / 500) - 0.5) / 0.14, 2.0)) / 2.0));
    analogWrite(led_pin, int(pwm_val));
    delay(5);
}