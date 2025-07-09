/*
Це модуль який відповідає за зчитування голоски енкодера а також її натискання
*/

// Констані значення виводів плати для відповідних виводів енкодера
#define ENCODER_PIN_A D5 // GPIO14
#define ENCODER_PIN_B D6 // GPIO12
#define ENCODER_PIN_BUTTON D7

volatile uint8_t selectionLimit = 4;

volatile int lastEncoded = 0;
volatile int encoderValue = 0; // Значення енкодера
volatile uint8_t selectionIndex = 0; // Значення обрання опції
volatile bool stateButton = 0; // Значення статусу кнопки
volatile int toggleButton = 0; // Значення перемикання кнопки

int encoderValue_old = 0; // Минуле значення енкодера
volatile int selectionIndex_old = 3; // Минуле значення обрання опції
volatile bool stateButton_old = 1; // Минуле значення статусу кнопки
volatile int toggleButton_old = 0; // Минуле значення перемикання кнопки
volatile bool flag = 0;

// Зчитування напрямку прокручування енкодера
void IRAM_ATTR updateEncoder() {
  int MSB = digitalRead(ENCODER_PIN_A);
  int LSB = digitalRead(ENCODER_PIN_B);

  int encoded = (MSB << 1) | LSB;
  int sum = (lastEncoded << 2) | encoded;

  if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011)
    encoderValue--;
  if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000)
    encoderValue++;

  lastEncoded = encoded;
}

// Налаштування енкодера
void setupEncoder() {
  pinMode(ENCODER_PIN_A, INPUT_PULLUP);
  pinMode(ENCODER_PIN_B, INPUT_PULLUP);
  pinMode(ENCODER_PIN_BUTTON, INPUT_PULLUP);

  Serial.begin(115200);

  // Ініціалізація lastEncoded
  int MSB = digitalRead(ENCODER_PIN_A);
  int LSB = digitalRead(ENCODER_PIN_B);
  lastEncoded = (MSB << 1) | LSB;

  // Прив'язка до переривань
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_A), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_B), updateEncoder, CHANGE);
}

// Цикл зчитування енкодера
void loopEncoder() {
  // Оновлення індексу вибору опції.
  selectionIndex = ((encoderValue / 4) % selectionLimit + selectionLimit) % selectionLimit;

  // Вивід значення індиксу вибору опції у консоль
  if (selectionIndex != selectionIndex_old) {
      Serial.print("selectionIndex: ");
      Serial.println(selectionIndex);
      selectionIndex_old = selectionIndex;
      flag = 1;
      toggleButton = 0;
  }
  // Вивід значення енкодера у консоль
  if (encoderValue / 4 != encoderValue_old / 4) {
    Serial.print("Encoder value: ");
    Serial.println(encoderValue / 4);
    encoderValue_old = encoderValue;
  }
  // Статус кнопки
  stateButton = !digitalRead(ENCODER_PIN_BUTTON);
  if (stateButton == HIGH && stateButton_old == LOW) {
    Serial.print("Button status: ");
    Serial.println(stateButton);
    // Статус перемикання кнопки
    toggleButton++;
    if (toggleButton > 1){
      toggleButton = 0;
    }
    Serial.print("Toggle status: ");
    Serial.println(toggleButton);
    toggleButton_old = !toggleButton;
    flag = 1; 
  }
  stateButton_old = stateButton;
}




