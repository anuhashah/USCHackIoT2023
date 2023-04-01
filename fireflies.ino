
  // put your main code here, to run repeatedly:
int buzzerPin = 8;

void setup() {
  pinMode(buzzerPin, OUTPUT);

  tone(buzzerPin, 1000, 2000);
}

void loop() {

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
