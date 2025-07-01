#include "encoder.h"
#include "display.h"
#include "function.h"

void setup() {
  Serial.begin(115200);
  setupDisplay(); // Конфігурація дисплею
  setupEncoder(); // Конфігурація енкодера
  welcomeScreen(); // Вітальна заставка на дисплеї
}

void loop() {
  loopEncoder(); // Цикл зчитування енкодера
  loopFunction(); // Цикл виконання функцій
}
