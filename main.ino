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

unsigned long startTime0 = 0;
unsigned long startTime1 = 0;
unsigned long startTime2 = 0;
unsigned long startTime3 = 0;
unsigned long startTime4 = 0;

const unsigned long intervaloMin = 2000;

int dotDuration = 200;
int dashDuration = 600;
int symbolGap = 200;
int letterGap = 800;

void setup() {
  pinMode(BUT0, INPUT);
  pinMode(BUT1, INPUT);
  pinMode(BUT2, INPUT);
  pinMode(BUT3, INPUT);
  pinMode(BUT4, INPUT);

  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void blinkMorseChar(char symbol, int ledPin) {
  digitalWrite(ledPin, HIGH);
  delay(symbol == '.' ? dotDuration : dashDuration);
  digitalWrite(ledPin, LOW);
  delay(symbolGap);
}

void blinkMorse(String code, int ledPin) {
  for (int i = 0; i < code.length(); i++) {
    blinkMorseChar(code[i], ledPin);
  }
  delay(letterGap);
}

void loop() {
  unsigned long now = millis();

  if (digitalRead(BUT0) == HIGH && now - startTime0 >= intervaloMin) {
    blinkMorse(".-..", LED0);
    startTime0 = now;
  }

  if (digitalRead(BUT1) == HIGH && now - startTime1 >= intervaloMin) {
    blinkMorse("..-", LED1);
    startTime1 = now;
  }

  if (digitalRead(BUT2) == HIGH && now - startTime2 >= intervaloMin) {
    blinkMorse("-.-.", LED2);
    startTime2 = now;
  }

  if (digitalRead(BUT3) == HIGH && now - startTime3 >= intervaloMin) {
    blinkMorse(".-", LED3);
    startTime3 = now;
  }

  if (digitalRead(BUT4) == HIGH && now - startTime4 >= intervaloMin) {
    blinkMorse("...", LED4);
    startTime4 = now;
  }
}
