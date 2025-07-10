#include "encoder.h"
#include "display.h"
#include "function.h"

unsigned long start = millis();

void setup() {
  Serial.begin(115200);
  setupDisplay(); // Конфігурація дисплею
  setupEncoder(); // Конфігурація енкодера
  welcomeScreen(); // Вітальна заставка на дисплеї
  Serial.println("\n\n=============");
  Serial.println("Setup success");
  Serial.println("=============");
}

void loop() {
  loopEncoder(); // Цикл зчитування енкодера
  if (flag == 1)  // Зчитування активації енкодера для запобігання нескінченного повторення циклу.
    loopFunction(); // Цикл виконання функцій
}
