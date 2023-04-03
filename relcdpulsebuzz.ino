// pulse sensor
#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM maths.
#include <PulseSensorPlayground.h>     
const int PulseWire = 0;       // PulseSensor WIRE to ANALOG PIN 0
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore.
                               
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor

//lcd
#include <LiquidCrystal.h> // include the library code:
LiquidCrystal lcd(12, 11, 5, 4, 3, 6); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)

//buzzer
int buzzerPin = 8;

//button
const int buttonPin=2;
volatile int buttonstate=0;
volatile boolean flag=false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);          // For Serial Monitor

  //pulse
  pulseSensor.analogInput(PulseWire);  
  pulseSensor.setThreshold(Threshold);  
  // Double-check the "pulseSensor" object was created and "began" seeing a signal.
   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset. 
  }

  //lcd
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // Clears the LCD screen
  lcd.clear();

  //buzzer
  pinMode(buzzerPin, OUTPUT);
  tone(buzzerPin, 1000, 2000);

  //button
  pinMode(buttonPin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), finish, CHANGE);
  
}
void loop() {
  // put your main code here, to run repeatedly:
  int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
                                               // "myBPM" hold this BPM value now.
  if (pulseSensor.sawStartOfBeat()) 
  {            // Constantly test to see if "a beat happened".
    Serial.println("♥  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
    Serial.print("BPM: ");                        // Print phrase "BPM: "
  
    Serial.println(myBPM); 
    // Print the value inside of myBPM.
    // Print a message to the LCD.
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print("my BPM");
  
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);
    // Print a message to the LCD.
    lcd.print(myBPM);
    highbp(myBPM);
    }
}                                             

void highbp(int bp)
{
  if (bp>100)
  {
    Serial.print("high bp");
    while(!flag)
    {
      buzz();
    }
  }
  else
  {
    Serial.print("normal bp");
  }
}

void pause() {
  int PAUSE = 10; // Puase time = 10 ms
  tone(buzzerPin, 0); // Pause
  delay(PAUSE);
}

void buzz()
{
  Serial.println("Buzzing ");
  int QUARTER = 342.857;
  int DQUARTER = 514.286;
  int EIGTH = 171.4285;

  if (flag)
  {
    exit(0);
  }
  // 60,000 (ms) ÷ BPM = duration of a quarter note
  tone(buzzerPin, 233.08); // B Flat
  delay(QUARTER); // Quarter note = 1 beat

  pause(); // distinguishes notes from each other

  tone(buzzerPin, 1174.66); // D
  delay(DQUARTER); // Dotted Quarter = 1.5 beats

  pause();

  tone(buzzerPin, 932.33); // B Flat 5
  delay(DQUARTER); // Dotter Quarter
  
  pause();

  tone(buzzerPin, 311.13); // E Flat 4
  delay(QUARTER); // Quarter note 

  pause();

  tone(buzzerPin, 698.46); // F5
  delay(EIGTH); // Eigth Note = 1/2 beat

  pause();

  tone(buzzerPin, 622.25); // E Flat 5
  delay(EIGTH); // Eigth Note

  pause();

  tone(buzzerPin, 698.46); // F5
  delay(EIGTH); // Eigth Note

  pause();

  tone(buzzerPin, 932.33); // B Flat 5
  delay(DQUARTER); // Dotted Quarter

  pause();

  tone(buzzerPin, 207.65); // A Flat 3
  delay(QUARTER); // Quarter

  pause();

  tone(buzzerPin, 523.25); // C5
  delay(EIGTH); // Eigth

  pause();

  tone(buzzerPin, 466.16); // B Flat 4
  delay(EIGTH); // Eigth

  pause();

  tone(buzzerPin, 523.25); // C5
  delay(EIGTH); // Eigth

  pause();

  tone(buzzerPin, 622.25); // E Flat 5
  delay(DQUARTER); // Dotted

  pause();

  tone(buzzerPin, 207.65); // A Flat 3
  delay(QUARTER); // Quarter

  pause();

  tone(buzzerPin, 523.25); // C5
  delay(EIGTH); // Eigth

  pause();

  tone(buzzerPin, 466.16); // B Flat 4
  delay(QUARTER); //Quarter

  pause();

  tone(buzzerPin, 523.25); // C5
  delay(EIGTH); // Eigth

  pause();

  tone(buzzerPin, 622.25); // E Flat 5
  delay(EIGTH); // Eigth

  pause();

  tone(buzzerPin, 698.46); // F5
  delay(EIGTH); // Eigth

  tone(buzzerPin,0);
}
  

void finish()
{
  //tone(buzzerPin, 0);
  flag=true;
  Serial.println("interrupt");
  
  //tone(buzzerPin, 0);
  exit(0);
}
