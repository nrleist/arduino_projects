//set the pins for the button and buzzer
int firstKeyPin = 2;
int secondKeyPin = 3;
int thirdKeyPin = 4;

int redPin = 5; 
int yellowPin = 6;
int greenPin = 7;

int buzzerPin = 9;

void doLights(bool red, bool yellow, bool green){
  if(red) {
    digitalWrite(redPin, HIGH);
  } else {
    digitalWrite(redPin, LOW);
  }

  if(yellow) {
    digitalWrite(yellowPin, HIGH);
  } else {
    digitalWrite(yellowPin, LOW);
  }

  if(green) {
    digitalWrite(greenPin, HIGH);
  } else {
    digitalWrite(greenPin, LOW);
  }
}

void setup() {
  //set the button pins as inputs
  pinMode(firstKeyPin, INPUT_PULLUP);
  pinMode(secondKeyPin, INPUT_PULLUP);
  pinMode(thirdKeyPin, INPUT_PULLUP);

  //set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);

  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {

  if(digitalRead(firstKeyPin) == LOW && digitalRead(secondKeyPin) == LOW && digitalRead(thirdKeyPin) == LOW){
    doLights(true, true, true);
    tone(buzzerPin, 500);
  }
  else if(digitalRead(firstKeyPin) == LOW && digitalRead(secondKeyPin) == LOW){
    doLights(false, false, false);
    tone(buzzerPin, 100);
  }
  else if(digitalRead(secondKeyPin) == LOW && digitalRead(thirdKeyPin) == LOW) {
    doLights(false, false, false);
    tone(buzzerPin, 170);
  }
  else if(digitalRead(firstKeyPin) == LOW && digitalRead(thirdKeyPin) == LOW){
    doLights(false, false, false);
    tone(buzzerPin, 410);
  }
  else if (digitalRead(firstKeyPin) == LOW) {      //if the first key is pressed
    doLights(true, false, false);
    tone(buzzerPin, 262);       //play the frequency for c
  }
  else if (digitalRead(secondKeyPin) == LOW) { //if the second key is pressed
    doLights(false, true, false);
    tone(buzzerPin, 330);                     //play the frequency for e
  }
  else if (digitalRead(thirdKeyPin) == LOW) { //if the third key is pressed
    doLights(false, false, true);
    tone(buzzerPin, 390);                     //play the frequency for g
  }
  else {
    doLights(false, false, false);
    noTone(buzzerPin);     //if no key is pressed turn the buzzer off
  }
}
