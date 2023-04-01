#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM maths.
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.  

// include the library code:
#include <LiquidCrystal.h>

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore.
                               // Use the "Getting Started Project" to fine-tune Threshold Value beyond default setting.
                               // Other
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor
// put your main code here, to run repeatedly:
int buzzerPin = 8;
// button
const int buttonPin=6;
int buttonstate = 0;

//stop button
boolean stop = true;

void setup() {
  Serial.begin(9600);          // For Serial Monitor
  // Configure the PulseSensor object, by assigning our variables to it.
  pulseSensor.analogInput(PulseWire);  
  pulseSensor.setThreshold(Threshold);  
  // Double-check the "pulseSensor" object was created and "began" seeing a signal.
   if (pulseSensor.begin()) {
    Serial.println("Pulse is sensed");  //This prints one time at Arduino power-up,  or on Arduino reset. 
  }

   // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // Clears the LCD screen
  lcd.clear();
  Serial.println("Enter alarm time:");
  int time = Serial.parseFloat();

  //buzzer
  pinMode(buzzerPin, OUTPUT);
  tone(buzzerPin, 1000, 2000);

  //button
  pinMode(buttonPin, INPUT);

}

void loop() {
  if (stop==true)
  {
    // put your main code here, to run repeatedly:
    int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
                                                 // "myBPM" hold this BPM value now.
    
    float current_time=9.15;
    //if (myBPM >100 && myBPM < 70) //|| current_time>=time
      //{
      if (stop == true)
        buzz();
      //}
    
    
    if (pulseSensor.sawStartOfBeat()) 
    {            // Constantly test to see if "a beat happened".
      Serial.println("♥  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
      Serial.print("BPM: ");                        // Print phrase "BPM: "
    
      Serial.println(myBPM); 
      // Print the value inside of myBPM.
      // Print a message to the LCD.
      lcd.setCursor(0,0);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("my BPM:");
      lcd.print(myBPM);
    
      // set the cursor to column 0, line 1
      // (note: line 1 is the second row, since counting begins with 0):
      lcd.setCursor(0, 1);
      // Print a message to the LCD.
      lcd.print("Time:");
      lcd.print(current_time);
      
  
    }
  
    buttonstate=digitalRead(buttonPin);
     if (buttonstate == HIGH) {
      
      digitalWrite(buzzerPin, LOW);
      stop=false;
    } 
    delay(200); 
  }
  
}

void buzz()
{
  // 60,000 (ms) ÷ BPM = duration of a quarter note
      tone(buzzerPin, 233.08); // B Flat
      delay(342.857); // Quarter note = 1 beat
    
      tone(buzzerPin, 0); // Pause
      delay(10); 
    
      tone(buzzerPin, 1174.66); // D
      delay(514.286); // Dotted Quarter = 1.5 beats
    
      tone(buzzerPin, 0); // Pause
      delay(10); 
    
      tone(buzzerPin, 932.33); // B Flat 5
      delay(514.286); // Dotter Quarter
      
      tone(buzzerPin, 0); // Pause
      delay(10);
    
      tone(buzzerPin, 311.13); // E Flat 4
      delay(342.857); // Quarter note 
    
      tone(buzzerPin, 0); // Pause
      delay(10);
    
      tone(buzzerPin, 698.46); // F5
      delay(329.67); // Eigth Note = 1/2 beat
    
      tone(buzzerPin, 0); // Pause
      delay(10);
    
      tone(buzzerPin, 622.25); // E Flat 5
      delay(329.67); // Eigth Note
    
      tone(buzzerPin, 0); // Pause
      delay(10);
    
      tone(buzzerPin, 698.46); // F5
      delay(329.67); // Eigth Note
    
      tone(buzzerPin, 0); // Pause
      delay(10);
    
      tone(buzzerPin, 932.33); // B Flat 5
      delay(514.286); // Dotted Quarter
    
      tone(buzzerPin, 0); // Pause
      delay(10);
    
      tone(buzzerPin, 207.65); // A Flat 3
      delay(342.857); // Quarter
    
      tone(buzzerPin, 0); // Pause
      delay(10);
    
      tone(buzzerPin, 523.25); // C5
      delay(329.67); // Eigth
    
      tone(buzzerPin, 0); // Pause
      delay(10);
    
      tone(buzzerPin, 466.16); // B Flat 4
      delay(342.857); // Eigth
    
      tone(buzzerPin, 0); // Pause
      delay(10);
    
      tone(buzzerPin, 523.25); // C5
      delay(329.67); // Eigth
    
      tone(buzzerPin, 0); // Pause
      delay(10);
    
      tone(buzzerPin, 622.25); // E Flat 5
      delay(514.286); // Dotted
    
      tone(buzzerPin, 0); // Pause
      delay(10);
    
      tone(buzzerPin, 207.65); // A Flat 3
      delay(342.857); // Quarter
    
      tone(buzzerPin, 0); // Pause
      delay(10);
    
      tone(buzzerPin, 523.25); // C5
      delay(329.67); // Eigth
    
      tone(buzzerPin, 0); // Pause
      delay(10);
    
      tone(buzzerPin, 466.16); // B Flat 4
      delay(342.857); //Quarter
    
      tone(buzzerPin, 0); // Pause
      delay(10);  
    
      tone(buzzerPin, 523.25); // C5
      delay(329.67); // Eigth
    
      tone(buzzerPin, 0); // Pause
      delay(10);
    
      tone(buzzerPin, 622.25); // E Flat 5
      delay(329.67); // Eigth
    
      tone(buzzerPin, 0); // Pause
      delay(10);
    
      tone(buzzerPin, 698.46); // F5
      delay(329.67); // Eigth
}
