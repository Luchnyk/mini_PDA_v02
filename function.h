// Статус обання опції у меню
void menuSelection() {
  if (selectionIndex == 0) // Вивід зображення меню
    menuScreen0();
  if (selectionIndex == 1) // Вивід зображення та виділення першої опції меню
    menuScreen1();
  if (selectionIndex == 2) // Вивід зображення та виділення другої опції меню
    menuScreen2();
  if (selectionIndex == 3) // Вивід зображення та виділення третьої опції меню
    menuScreen3();
}

// Функції програми
void function0() { // Перша функція програми
// Порожня
  menuScreen0();
}
void function1() { // Перша функція програми
// Порожня
  menuScreen0();
  if (toggleButton == 1)
    functionScreen0();
}
void function2() { // Друга функція програми
// Порожня
  menuScreen0();
  if (toggleButton == 1)
    functionScreen0();
}
void function3() { // Третя функція програми
// Порожня
  menuScreen0();
  if (toggleButton == 1)
    functionScreen0();
}

// Цикл функцій програми
void loopFunction() { 
  switch (selectionIndex) {
    case 0: menuScreen0();
  }
}