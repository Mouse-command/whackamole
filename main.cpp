#include <M5Core2.h>

int x = 160;
int y = 200;
int mx = 50;
int my = 50;

void mole_appear(TouchPoint_t pos);

void setup() {
  M5.begin();
  M5.Lcd.fillScreen(BLUE);
  M5.Lcd.fillCircle(160, 200, 10, BLACK);
  

}

void loop() {
  // move whack to finger
  TouchPoint_t pos = M5.Touch.getPressPoint();
  bool touchStateNow = ( pos.x == -1 ) ? false : true;
  M5.Lcd.fillCircle(x, y, 10, BLACK);
  if (touchStateNow) {
    M5.Lcd.fillCircle(x, y, 10, BLUE);
    x = pos.x;
    y = pos.y;
  }
  if (pos.x >= 60 && pos.y >= 60 && pos.x >= -1)
    M5.Lcd.fillRoundRect(mx, my, 30, 30, 10, OLIVE);
  if (pos.x <= 60 && pos.y <= 60)
    M5.Lcd.fillRoundRect(mx, my, 30, 30, 10, BLUE);  
}

//void mole_appear(TouchPoint_t pos) {
//  M5.Lcd.fillRoundRect(mx, my, 30, 30, 10, OLIVE);

//    M5.Lcd.fillScreen(BLUE);
//}
