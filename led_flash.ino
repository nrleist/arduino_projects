
const int led_pin = 6;
const int ptent_pin = 0; 
double value = 0;
int wait_time = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  pinMode(ptent_pin, INPUT);

  Serial.begin(9600); 

  digitalWrite(led_pin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(ptent_pin);
  wait_time = map(value, 1023, 0, 50, 1000);
  double led_value = map(value, 1023, 0, 0, 255);
  Serial.println(value);

  //analogWrite(led_pin, led_value);
  //delay(10);

  digitalWrite(led_pin, HIGH);
  delay(wait_time);
  digitalWrite(led_pin, LOW);
  delay(wait_time);

}
