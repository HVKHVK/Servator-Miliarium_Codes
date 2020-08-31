#include <DS3231.h>
#include <Wire.h>

bool century = false;
bool h12Flag = false;
bool pmFlag = false;
DS3231 clock;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(clock.getYear(), DEC);
  Serial.print(",");
  Serial.print(clock.getMonth(century), DEC);
  Serial.print(",");
  Serial.print(clock.getDate(), DEC);
  Serial.print(",");
  Serial.print(clock.getHour(h12Flag, pmFlag), DEC);
  Serial.print(",");  
  Serial.print(clock.getMinute(), DEC);
  Serial.print(","); 
  Serial.print(clock.getSecond(), DEC);
  Serial.print("\n");
  delay(1000);
}
