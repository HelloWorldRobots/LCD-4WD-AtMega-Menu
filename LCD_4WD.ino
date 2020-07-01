/* Created By Akshat Sharma. Modified at 7/1/2020 */
/* This, is for LCD without any pot. (Incase you were wondering).. */

#include <LiquidCrystal.h> 
const int ButtonPin = 29;
int ButtonState; 
int Contrast=0;
LiquidCrystal lcd(23, 24, 25, 26, 27, 28);


void setup() {
  analogWrite(22, Contrast);
  pinMode(ButtonPin, INPUT_PULLUP);
   lcd.begin(16,2);
  program();
  
  

}

void loop() {
 

}

void program(){
  String start[] = {"Following Mode", "Obstacle Avoider", "Maze Mode", "Manual Mode"};
  String motor[] = {
   "M1", "M2", "M3", "M4"
  };
  String Speed[] = {
    "100", "50", "25"
  };
  lcd.print("Select the mode: ");
  delay(2000);
  lcd.clear();
  for(int i = 0; i < 4; i++){

    lcd.begin(16,2);
    lcd.print(start[i]);
    delay(2500);
    int ButtonState = digitalRead(ButtonPin);
    if(ButtonState == LOW){
      lcd.clear();
      delay(500);
      lcd.print("Setting it up...");
      delay(500);
      lcd.clear();
      lcd.print("Set to " + start[i]);
      delay(670);
      lcd.clear();
 
      lcd.print("Starting...");
      delay(950);
      lcd.clear();
      lcd.print("Select the Speed of the Motors");
      delay(1000);
      lcd.clear();
      for(int a; a < 3; a++){
        lcd.print("Speed: ");
        lcd.print(Speed[a]);
        delay(2500);
        int ButtonState = digitalRead(ButtonPin);
        if(ButtonState == LOW){
          if(Speed[a] == "100"){
            lcd.clear();
            lcd.print("Set to " + Speed[a]);
            delay(1000);
            lcd.clear();
            break;
          }
           if(Speed[a] == "50"){
         
            lcd.clear();
            lcd.print(" Set to " + Speed[a]);
            delay(1000);
            lcd.clear();
            break;
            
          }
           if(Speed[a] == "25"){
       
            lcd.clear();
            lcd.print("Set to " + Speed[a]);
            delay(1000);
            lcd.clear();
            break;
            
          }
        }
        lcd.clear();
      }
      
      /*if( i == 1){
        // Do.. Following Mode
        
      }
      if( i == 2){
        // Do.. Obstacle Avoider
        
      }
      if( i == 3){
        // Do.. Maze Mode
        
      }
      if( i == 4){
        // Do.. Manual Mode
        
      }
      */
      lcd.clear();
      lcd.print(start[i]);
      break;
    }
    lcd.clear();
    delay(500);
    
    
  }
}
