#include <Arduino.h>
#include <Pin.h>

// Declare variables for storing time data
byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;

// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
  return ((val / 10 * 16) + (val % 10));
}

// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return ((val / 16 * 10) + (val % 16));
}

// date and time from the DS1307 + OLED
void getDateDs1307()
{
  // Reset the register pointer
  Wire.beginTransmission(DS1307_I2C_ADDRESS);
  Wire.write(0);
  Wire.endTransmission();

  Wire.requestFrom(DS1307_I2C_ADDRESS, 7);

  // Read the data
  second = bcdToDec(Wire.read() & 0x7F);
  minute = bcdToDec(Wire.read());
  hour = bcdToDec(Wire.read() & 0x3F);
  dayOfWeek = bcdToDec(Wire.read());
  dayOfMonth = bcdToDec(Wire.read());
  month = bcdToDec(Wire.read());
  year = bcdToDec(Wire.read());

  // Print the time 
  OLED.clearDisplay();             // ลบภาพในหน้าจอทั้งหมด
  OLED.setTextColor(WHITE, BLACK); // กำหนดข้อความสีขาว ฉากหลังสีดำ
  OLED.setCursor(30, 30);          // กำหนดตำแหน่ง x,y ที่จะแสดงผล
  OLED.setTextSize(1);             // กำหนดขนาดตัวอักษร
  OLED.print(hour, DEC);           // ชั่วโมง
  OLED.print(":");
  OLED.print(minute, DEC);         // นาที
  OLED.print(":");
  OLED.print(second, DEC);         // วินาที

  //Print the time กฟะำ
  OLED.setTextColor(WHITE, BLACK); // กำหนดข้อความสีขาว ฉากหลังสีดำ
  OLED.setCursor(30, 40);          // กำหนดตำแหน่ง x,y ที่จะแสดงผล
  OLED.setTextSize(1);             // กำหนดขนาดตัวอักษร
  OLED.print(dayOfMonth, DEC);           // ชั่วโมง
  OLED.print("/");
  OLED.print(month, DEC);         // นาที
  OLED.print("/");
  OLED.print(year, DEC);         // วินาที  
}

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  if (!OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { // สั่งให้จอ OLED เริ่มทำงานที่ Address 0x3C
    Serial.println("SSD1306 allocation failed");
  }
  else
  {
    Serial.println("OLED Start Working !!!");
  }

}

void loop()
{
  getDateDs1307(); // Get the time data from the RTC and print it


  OLED.display();  // สั่งให้จอแสดงผล
  delay(1000);
}