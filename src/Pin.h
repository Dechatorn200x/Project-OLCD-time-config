#ifndef Pin_h
#define Pin_h

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// กำหนดขาต่อ I2C กับจอ OLED
#define OLED_RESET -1  //ขา reset เป็น -1 ถ้าใช้ร่วมกับขา Arduino reset
#define SCREEN_WIDTH 128  // pixel ความกว้าง
#define SCREEN_HEIGHT 64  // pixel ความสูง
Adafruit_SSD1306 OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// กำหนดขาต่อ I2C address of Tiny RTC
#define DS1307_I2C_ADDRESS 0x68 

// กำหนดขาสวิต
enum Pins {
  SW1 = A0,
  SW2 = A1,
  SW3 = A2,
  SW4 = A3,
};

//relay OUTPUT
#define Relay1 26
#define Relay2 27
#define Relay3 28
#define Relay4 29

 




#endif