/*
Це модуль який відповідає за вивід зображення на дисплей.
*/

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Константи для налаштування дисплею
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Зображення для екрану конвертовані у біти
#include "images_bits.h"

// Налаштування дисплею
void setupDisplay() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

// Вітальна заставка
void welcomeScreen() {
  display.drawBitmap(32, 0, IMAGE_Welcome_bits, 64, 64, 1);
  display.display();
  delay(1000);
}

// Заставки для меню
void menuScreen0() { // Заствака без виділення
  display.clearDisplay();
  display.drawBitmap(0, 0, IMAGE_Menu0_bits, 128, 64, 1); 
  display.display();
}
void menuScreen1() { // Заставка з виділенням першого пункту
  display.clearDisplay();
  display.drawBitmap(0, 0, IMAGE_Menu1_bits, 128, 64, 1); 
  display.display();
}
void menuScreen2() { // Заставка з виділенням другого пункту
  display.clearDisplay();
  display.drawBitmap(0, 0, IMAGE_Menu2_bits, 128, 64, 1); 
  display.display();
}
void menuScreen3() { // Заставка з виділенням третього пункту
  display.clearDisplay();
  display.drawBitmap(0, 0, IMAGE_Menu3_bits, 128, 64, 1); 
  display.display();
}

// Заставка для функції null
void functionNullScreen0() { // Заствка для демонстраційної функції
  display.clearDisplay();
  display.drawBitmap(0, 0, IMAGE_FunctionNull_bits, 128, 64, 1);  
  display.display();
}

void functionNullScreenQuit() { // Заствка для демонстраційної функції
  display.clearDisplay();
  display.drawBitmap(0, 0, IMAGE_FunctionNullQuit_bits, 128, 64, 1);  
  display.display();
}

// Заставки для функцій
void functionScreen1() { // Заствка для демонстраційної функції
  display.clearDisplay();
  display.drawBitmap(5, 21, IMAGE_Folder_bits, 18, 16, 1); 
  display.drawBitmap(0, 0, IMAGE_Background_bits, 128, 64, 1);  
  display.display();
}
