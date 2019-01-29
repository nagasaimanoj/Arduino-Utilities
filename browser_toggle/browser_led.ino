#include <ESP8266WiFi.h>

int LED = D2;
char* ssid = "********";
char* password = "********";
bool status_led = 0;

WiFiServer server(80);

void setup() {
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);

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

    if (req.indexOf("/ledoff") != -1) {
        status_led = 0;
        digitalWrite(LED, LOW);

        client.println("<a href='/ledon'>turn on</a>");
    } else if (req.indexOf("/ledon") != -1) {
        status_led = 1;
        digitalWrite(LED, HIGH);

        client.println("<a href='/ledoff'>turn off</a>");
    } else if (req.indexOf("/status") != -1) {
        client.println(status_led);
    }
}