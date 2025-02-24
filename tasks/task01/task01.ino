struct PinData {
  uint8_t pin;           // Номер пина
  uint32_t interval;      // Интервал переключения (полупериод)
  volatile uint32_t prevTime; // Время последнего переключения
  bool state;             // Текущее состояние пина
};

PinData pins[] = {
  {3,  10000, 0, LOW}, // 10 мс (20 мс период)
  {5,   1000, 0, LOW}, // 1 мс (2 мс период)
  {6,    500, 0, LOW}, // 500 мкс (1 мс период)
  {9,    100, 0, LOW}, // 100 мкс (200 мкс период)
  {10,    50, 0, LOW}  // 50 мкс (100 мкс период)
};
const uint8_t numPins = sizeof(pins)/sizeof(PinData);

void setup() {
  for (uint8_t i = 0; i < numPins; i++) {
    pinMode(pins[i].pin, OUTPUT);
  }
}

void loop() {
  uint32_t currentTime = micros();

  for (uint8_t i = 0; i < numPins; i++) {
    if (currentTime - pins[i].prevTime >= pins[i].interval) {
      pins[i].prevTime = currentTime;
      
      pins[i].state = !pins[i].state;
      digitalWrite(pins[i].pin, pins[i].state);
    }
  }
}
