const uint8_t numPins = 5;
const uint8_t pins[] = {3, 5, 6, 9, 10};
const uint32_t intervals[] = {10000, 1000, 500, 100, 50}; // Полупериоды
uint32_t prevToggleTime[numPins];
bool pinStates[numPins] = {LOW};

void setup() {
  for (uint8_t i = 0; i < numPins; i++) {
    pinMode(pins[i], OUTPUT);
    prevToggleTime[i] = micros();
  }
}

void loop() {
  uint32_t currentTime = micros();
  
  for (uint8_t i = 0; i < numPins; i++) {
    if (currentTime - prevToggleTime[i] >= intervals[i]) {
      prevToggleTime[i] = currentTime;
      pinStates[i] = !pinStates[i];
      digitalWrite(pins[i], pinStates[i]);
    }
  }
}