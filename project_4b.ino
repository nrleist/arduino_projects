/*
  SparkFun Inventor’s Kit
  Circuit 4B - Temperature Sensor

  The LCD will display readings from a temperature sensor in degrees Celsius and Fahrenheit.

  This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
  This code is completely free for any use.

  View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v41
  Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
*/

#include <LiquidCrystal.h>                  //the liquid crystal library contains commands for printing to the display
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);    // tell the RedBoard what pins are connected to the display

float voltage = 0;                          //the voltage measured from the TMP36
float degreesC = 0;                         //the temperature in Celsius, calculated from the voltage
float degreesF = 0;                         //the temperature in Fahrenheit, calculated from the voltage

void setup() {

  lcd.begin(16, 2);                         //tell the lcd library that we are using a display that is 16 characters wide and 2 characters high
  lcd.clear();                              //clear the display
}

void loop() {

  voltage = analogRead(A0) * 0.004882813;   //convert the analog reading, which varies from 0 to 1023, back to a voltage value from 0-5 volts
  degreesC = (voltage - 0.5) * 100.0;       //convert the voltage to a temperature in degrees Celsius
  degreesF = degreesC * (9.0 / 5.0) + 32.0; //convert the voltage to a temperature in degrees Fahrenheit

  lcd.clear();                              //clear the LCD

  //lcd.setCursor(0, 0);                      //set the cursor to the top left position
  //lcd.print("Degrees C: ");                 //print a label for the data
  //lcd.print(degreesC);                      //print the degrees Celsius

  lcd.setCursor(0, 0);                      //set the cursor to the lower left position
  lcd.print("Degrees F: ");                 //Print a label for the data
  lcd.print(degreesF);                      //print the degrees Fahrenheit

  LCD_progress_bar(1, degreesF, 0, 100);

  delay(1000);                              //delay for 1 second between each reading (this makes the display less noisy)
}

void LCD_progress_bar (int row, int var, int minVal, int maxVal) {
  int block = map(var, minVal, maxVal, 0, 16);   // Block represent the current LCD space (modify the map setting to fit your LCD)
  int line = map(var, minVal, maxVal, 0, 80);     // Line represent the theoretical lines that should be printed 
  int bar = (line-(block*5));                             // Bar represent the actual lines that will be printed
  
  /* LCD Progress Bar Characters, create your custom bars */

  byte bar1[8] = { 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10};
  byte bar2[8] = { 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18};
  byte bar3[8] = { 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C};
  byte bar4[8] = { 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E};
  byte bar5[8] = { 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};
  lcd.createChar(1, bar1);
  lcd.createChar(2, bar2);
  lcd.createChar(3, bar3);
  lcd.createChar(4, bar4);
  lcd.createChar(5, bar5);
  
  for (int x = 0; x < block; x++)                        // Print all the filled blocks
  {
    lcd.setCursor (x, row);
    lcd.write (1023);
  }
  
  lcd.setCursor (block, row);                            // Set the cursor at the current block and print the numbers of line needed
  if (bar != 0) lcd.write (bar);
  if (block == 0 && line == 0) lcd.write (1022);   // Unless there is nothing to print, in this case show blank
  
  for (int x = 16; x > block; x--)                       // Print all the blank blocks
  {
    lcd.setCursor (x, row);
    lcd.write (1022);
  }
}
