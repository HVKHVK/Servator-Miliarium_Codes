#include "U8glib.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);

bool status_of_gps = false;
bool status_of_log = false;
int battery_percentage = 100;

void setup() {
}

void loop() {

  u8g.firstPage();  
  do {
    draw();
    draw_status_of_gps();
    draw_status_of_log();
    draw_battery();
  } while( u8g.nextPage() );
    delay(1000);
}

void draw(void)
{
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 0, 15, "Servator");
  u8g.drawStr( 0, 35, "GPS");
  u8g.drawStr( 0, 55, "LOG");
}

void draw_status_of_gps(void){
  u8g.setFont(u8g_font_unifont);
  if (status_of_gps == true){
      u8g.drawStr( 30, 35, "+");
  }
  else if (status_of_gps == false){
      u8g.drawStr( 30, 35, "-");
  }
}

void draw_status_of_log(void){
  u8g.setFont(u8g_font_unifont);
  if (status_of_log == true){
      u8g.drawStr( 30, 55, "+");
  }
  else if (status_of_log == false){
      u8g.drawStr( 30, 55, "-");
  }
}

void draw_battery(void){
  u8g.drawBox(103,6,6,7);
  u8g.drawFrame(96,13,20,39);
  if ( battery_percentage >= 85){
      u8g.drawBox(98,15,16,5);
      u8g.drawBox(98,21,16,5);
      u8g.drawBox(98,27,16,5);
      u8g.drawBox(98,33,16,5);
      u8g.drawBox(98,39,16,5);
      u8g.drawBox(98,45,16,5);
  }
  else if ( battery_percentage >= 70){
      u8g.drawBox(98,21,16,5);
      u8g.drawBox(98,27,16,5);
      u8g.drawBox(98,33,16,5);
      u8g.drawBox(98,39,16,5);
      u8g.drawBox(98,45,16,5);
  }
  else if ( battery_percentage >= 55){
      u8g.drawBox(98,27,16,5);
      u8g.drawBox(98,33,16,5);
      u8g.drawBox(98,39,16,5);
      u8g.drawBox(98,45,16,5);
  }
 else if ( battery_percentage >= 40){
      u8g.drawBox(98,33,16,5);
      u8g.drawBox(98,39,16,5);
      u8g.drawBox(98,45,16,5);
  }
 else if ( battery_percentage >= 25){
      u8g.drawBox(98,39,16,5);
      u8g.drawBox(98,45,16,5);
  }
 else if ( battery_percentage >= 10){
      u8g.drawBox(98,45,16,5);
  }
 else if ( battery_percentage > 0){
      u8g.drawLine(96,13,115,51);
  }
}
