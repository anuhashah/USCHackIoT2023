//buzzer
int buzzerPin = 8;


//button
const int buttonPin=2;
volatile int buttonstate=0;
volatile boolean flag=false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //buzzer
  pinMode(buzzerPin, OUTPUT);
  tone(buzzerPin, 1000, 2000);

  //button
  pinMode(buttonPin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), finish, CHANGE);
  while(!flag){
    buzz();
    
  }
}

void loop() {
  // put your main code here, to run repeatedly:

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

  pause();

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
