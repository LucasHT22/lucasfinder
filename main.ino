int BUT0 = A0;
int BUT1 = A1;
int BUT2 = A2;
int BUT3 = A3;
int BUT4 = SDA;

int LED0 = SCL;
int LED1 = TX;
int LED2 = RX;
int LED3 = SCK;
int LED4 = MISO;

char buttonLetters[5] = {'C', 'L', 'U', 'S', 'A'};
int buttons[5] = {BUT0, BUT1, BUT2, BUT3, BUT4};
int leds[5] = {LED0, LED1, LED2, LED3, LED4};

String target = "LUCAS";
String input = "";

unsigned long debounceDelay = 250;
unsigned long lastPress[5] = {0, 0, 0, 0, 0};

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(buttons[i], INPUT);
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
}

void lightAllLeds(int duration) {
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i], HIGH);
  }
  delay(duration);
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i], LOW);
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    if (digitalRead(buttons[i]) == HIGH && millis() - lastPress[i] > debounceDelay) {
      input += buttonLetters[i];
      lastPress[i] = millis();
      if (input.length() > target.length()) {
        input = input.substring(input.length() - target.length());
      }
      if (input == target) {
        lightAllLeds(2000);
        input = "";
      }
    }
  }
}
