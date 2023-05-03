#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
LiquidCrystal_I2C lcd(0x27, 16, 2);

char digitArray[6]; //to store the 5 digits entered and null character
int digitCount = 0; //to keep track of the number of digits entered

void initializeLCD() {
  lcd.init();
  lcd.backlight();
}

void displayCardWaiting() {
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("enter code");
}

void displayCardExists(String nom) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("hello");
  lcd.setCursor(0, 1);
  lcd.print(nom);
}

void displayCardDoesNotExist() {
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("invalid code");
}

void setup(){
  initializeLCD();
  Serial.begin(9600);  
  displayCardWaiting();
}

void loop(){
  char key = keypad.getKey();

  if (key == '#') { //refresh table if '#' is pressed
    for (int i = 0; i < 6; i++) { //clear digitArray
      digitArray[i] = '\0';
    }
    digitCount = 0; //reset digitCount 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("table refreshed");
    delay(1000);
    displayCardWaiting();
  }
  
  else if (digitCount < 5 && key >= '0' && key <= '9') { //if digit is pressed
    digitArray[digitCount] = key;
    digitCount++; 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(digitArray); 
  }

  
  
  if (digitCount == 5) { //print digits when 5 digits have been entered
    digitArray[5] = '\0'; //set last character to null

Serial.write(digitArray,5);
    digitCount = 0; //reset digitCount
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("digits entered");
    delay(1000);
    displayCardWaiting();
        for (int i = 0; i < 6; i++) { //clear digitArray
      digitArray[i] = '\0';
    }
  }

  /* Qt Input */
  if (Serial.available()) {
    char read = Serial.read(); //read data from Qt 
    String tab = "";
    tab = read;
    tab += Serial.readString();

 
    if (read == '0') {
      displayCardDoesNotExist();   delay(2000);
    }
    else {
      displayCardExists(tab);     delay(2000);
    }
    delay(1000);
    displayCardWaiting();
    delay(1000);
  }
}
