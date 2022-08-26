#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal_I2C.h> // Library for LCD
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
// SDA pin is connected to A4 and SCL pin to A5.
// LCD via I2C, default address 0x27 
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);


void setup() 
{
 pinMode(9, OUTPUT);    // sets the digital pin 13 as output  
  
  lcd.init();     // Initiate the LCD:
  lcd.clear(); 
  lcd.backlight();
  Serial.begin(9600);
   mlx.begin(); }
 
void loop()
{
 
 lcd.clear(); 
  mlx.begin(); 
   float body=(mlx.readObjectTempC());
   float body1=(mlx.readObjectTempF());
   double beep = (mlx.readObjectTempC());
     lcd.leftToRight();
     lcd.setCursor(1, 0);
     lcd.print("Temp = ");
     lcd.print(body);
     lcd.print("C");
      lcd.leftToRight();
     lcd.setCursor(1, 1);
     lcd.print("Temp = ");
     lcd.print(body1);
     lcd.print("F");
     
Serial.print("Ambient="); 
Serial.print(mlx.readAmbientTempC()); 
Serial.print("----BODY TemperaturE=");
Serial.print(mlx.readObjectTempC());// Serial.println("*C");
Serial.println("  ");
   int val=(map((mlx.readObjectTempC()),-70,382,0,122));
     if(beep >= 38)
  {
     digitalWrite(9, HIGH);    //Switch Solenoid ON
     delay(10000);
     digitalWrite(9, LOW);
     
      
  }
 

  
     
    
  
} 
