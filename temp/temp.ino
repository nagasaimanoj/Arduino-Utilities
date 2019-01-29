#include <ESP8266WiFi.h>

char ssid[] = "********";
char password[] = "********";

int pins[] = {5, 4, 14, 12};
int pins_status[] = {1, 1, 1, 1};

WiFiServer server(80);

void setup() {
    for (int i = 0; i < 4; i++) {
        pinMode(pins[i], OUTPUT);
        digitalWrite(pins[i], pins_status[i]);
    }

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    server.begin();
}

void loop() {
    WiFiClient client = server.available();

    if (!client) {
        return;
    }

    while (!client.available()) {
        delay(1);
    }

    String req = client.readStringUntil('\r');

    client.flush();

    if (req.indexOf("/btn1") != -1) {
        toggle(0);
    }
    if (req.indexOf("/btn2") != -1) {
        toggle(1);
    }
    if (req.indexOf("/btn3") != -1) {
        toggle(2);
    }
    if (req.indexOf("/btn4") != -1) {
        toggle(3);
    }
}

void toggle(int pin) {
    pins_status[pin] = !pins_status[pin];
    digitalWrite(pins[pin], pins_status[pin]);
}