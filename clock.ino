unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
unsigned long seconds;
int minutes;
int hours;
unsigned long num_60_s;
unsigned long num_60_m;
const unsigned long period = 1000;  //the value is a number of milliseconds

// include the library code:
#include <LiquidCrystal.h>

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600); // Starts the serial communication
     // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
    // Clears the LCD screen
  lcd.clear();
  seconds = 0;
  num_60_s = 0;
  num_60_m = 0;
  minutes = 0;
  hours = 0;
  startMillis = millis();  //initial start time
}

void loop() {
 currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  lcd.print("                ");  
  // Print a message to the LCD.
  unsigned long current_time = (currentMillis+startMillis);
  seconds = current_time/1000 - 60*num_60_s;
  minutes = current_time/1000/60 - 60*num_60_m;
  hours = minutes/60;
  if(seconds == 60){
    num_60_s += 1;
  }
  if(minutes == 60){
    hours += 1;
    num_60_m += 1;
  }
  lcd.setCursor(0, 1);
  lcd.print("Time:");
  lcd.print(hours);
  lcd.print(":");
  lcd.print(minutes);
  lcd.print(":");
  lcd.print(seconds);
}
