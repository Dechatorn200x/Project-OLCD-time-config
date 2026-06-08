#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // pixel ความกว้าง
#define SCREEN_HEIGHT 64  // pixel ความสูง

// กำหนดขาต่อ I2C กับจอ OLED
#define OLED_RESET -1  //ขา reset เป็น -1 ถ้าใช้ร่วมกับขา Arduino reset
Adafruit_SSD1306 OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int var = 0;  // ตัวแปรสำหรับทดสอบแสดงผล
void setup() {
  Serial.begin(9600);
  if (!OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // สั่งให้จอ OLED เริ่มทำงานที่ Address 0x3C
    Serial.println("SSD1306 allocation failed");
  } else {
    Serial.println("OLED Start Working !!!");
  }
}

void loop() {
  OLED.clearDisplay();              // ลบภาพในหน้าจอทั้งหมด    
  OLED.clearDisplay();              // ลบภาพในหน้าจอทั้งหมด
  OLED.setTextColor(WHITE, BLACK);  //กำหนดข้อความสีขาว ฉากหลังสีดำ
  OLED.setCursor(30, 30);             // กำหนดตำแหน่ง x,y ที่จะแสดงผล
  OLED.setTextSize(4);              // กำหนดขนาดตัวอักษร
  OLED.println("luv");             // แสดงผลข้อความ
  
  OLED.setTextColor(WHITE, BLACK);
  OLED.setCursor(110, 10);
  OLED.setTextSize(1);
  OLED.println(var, DEC);


  OLED.display();  // สั่งให้จอแสดงผล
  var++;
  delay(500);
}