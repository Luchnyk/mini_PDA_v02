/*
Це модуль коду який відповідає за функції програми
*/

uint8_t funcToggle = 0; // Змінна у яку записано індекс запущеної функції.
uint8_t funcToggle_old = 0; // Змінна у яку записано минулий індекс запущеної функції.

void functionNull() { // Null функція програми
  selectionLimit = 2; // Встановлення ліміту обрання опцій встановлених функцією.
  switch (selectionIndex) { // Графічне відображення функції в залежності від положення головки енкодера.
      case 0: functionNullScreen0(); break;
      case 1: {
        functionNullScreenQuit();
        if (toggleButton == 1) { // Повернення у меню.
          funcToggle = 0; // Повернення у меню.
          toggleButton = 0; // Скидаємо стан перемикання кнопки кнопки.
        }
        break;
      }
    }
}
void function1() { // Перша функція програми
  // Порожня
  functionNull();
}
void function2() { // Друга функція програми
  // Порожня
  functionNull();
}
void function3() { // Третя функція програми
  // Порожня
  functionNull();
}

// Цикл функцій програми
void loopFunction() {
  if (funcToggle == 0 && toggleButton == 1) { // Якщо ми у головному меню і натиснута кнопка вибору
    funcToggle = selectionIndex; // Запуск вибраної функції.
    Serial.print("Function:");
    Serial.println(funcToggle);
    toggleButton = 0; // Скидання стану перемикання кнопки.
  }
  if (funcToggle != funcToggle_old) {
    encoderValue = 0;  // Онуляція значення положення головки енкодера при зміні функції
    funcToggle_old = funcToggle;
  }
  switch (funcToggle) { // Запуск функції обраної в залежності від положення головки енкодера.
    case 0: { // Запуск меню
      selectionLimit = 4; // Встановлення ліміту обрання опцій меню.
      switch (selectionIndex) { // Графічне відображення меню в залежності від положення головки енкодера.
        case 0: menuScreen0(); break;
        case 1: menuScreen1(); break;
        case 2: menuScreen2(); break;
        case 3: menuScreen3(); break;
      }
      break;
    }
    case 1: function1(); break; // Запуск першої функції
    case 2: function2(); break; // Запуск другої функції
    case 3: function3(); break; // Запуск третьої функції
  }
}