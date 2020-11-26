//Automated Car Parking System//

#include <LiquidCrystal.h> 
#include<Wire.h>
#include<LiquidCrystal_I2C.h>
#include<Servo.h>   
LiquidCrystal_I2C lcd(0x27,16,2); 
Servo gate;
Servo gate1;        
int slot1 = 5;     
int slot2 = 4;      
int gateSensor = 11;
int gateSensor1 = 12;

void setup() 

{
 gate.attach(7);
 gate1.attach(6);       
 pinMode(slot1,INPUT);  
 pinMode(slot2,INPUT);
 pinMode(gateSensor,INPUT);
 pinMode(gateSensor1,INPUT);   
 lcd.init();      
 lcd.backlight();
 Serial.begin(9600);
 lcd.begin(16,2);
}

void loop() 
{
   gate.write(0);
   if (digitalRead(gateSensor) == LOW)
     {
      gate.write(90);   
      delay(1000);
     }

   gate1.write(0);

   if (digitalRead(gateSensor1) == LOW)
     {
      gate1.write(90);   
      delay(1000);
     }

  if( !(digitalRead(gateSensor)) && digitalRead(slot1) && digitalRead(slot2))   
     {
      lcd.setCursor(0,1);   
      lcd.print("Avail: sLOT1and2");  
      gate.write(90); 
      delay(1000);   
     }

   if( !(digitalRead(gateSensor)) && !(digitalRead(slot1)) && digitalRead(slot2))  
      {
         lcd.setCursor(0,1);   
         lcd.print("Available: sLOT2");  
         gate.write(90); 
         delay(1000); 
      }  

   if( !(digitalRead(gateSensor)) && digitalRead(slot1) && !(digitalRead(slot2))) 
       {
         lcd.setCursor(0,1);   
         lcd.print("Available: sLOT1");  
         gate.write(90);  
         delay(1000);                
       }

  if( !(digitalRead(gateSensor)) && !(digitalRead(slot1)) && !(digitalRead(slot2)))
        {
          lcd.clear();    
          lcd.setCursor(0,0);  
          lcd.print("Parking Full");
          gate.write(90);
          delay(3000);
        }        
   
  if( digitalRead(gateSensor))    
        { 
          lcd.clear();    
          lcd.setCursor(0, 0);   
          lcd.print("EXIT");    
        }

   if( digitalRead(gateSensor1))    
        { 
          lcd.clear();    
          lcd.setCursor(0, 0);   
          lcd.print("*Park car here*");    
        }

