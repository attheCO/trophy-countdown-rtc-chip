#include <LiquidCrystal.h>
#include <Time.h>
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

time_t syncProvider()     //this does the same thing as RTC_DS1307::get()
{
  return RTC.now().unixtime();
}

void setup() {
  Wire.begin();
  //Initialize the serial port, wire library and RTC module
  Serial.begin(9600);
  setSyncProvider(syncProvider); //need RTC chip installed to work. Otherwise, just counting down secs.
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  //clear screen
  lcd.clear();
  // Print a message to the LCD.
  lcd.print("COde champions");
  lcd.setCursor(0, 1);
  lcd.print("until ");
}

void loop () {
  
  time_t timeLeft,eventDate, nowTime; // setup the fields needed.
    nowTime = now();
    eventDate = 1459765800; // April 02, 2016 2pm CT (http://www.onlineconversion.com/unix_time.htm)
    timeLeft = (eventDate - nowTime) - 56014; // dedecut secs to match CT timezone : hacky I know

    // has event date arrived?
    if(timeLeft < 0 || timeLeft > eventDate){
      lcd.setCursor(6, 1);
      lcd.print("right now");
    } else {
      // Display the seconds left before event.      
      lcd.setCursor(6, 1);
      // when counting down zeros are left over, se we clear every time to prevent
      lcd.print("                "); //Print blanks to clear the row
      lcd.setCursor(6, 1);
      lcd.print(timeLeft);
      Serial.print(timeLeft);
      Serial.println();
      delay(1000);
    }
      
    
}
