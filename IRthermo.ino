#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
void setup() 
{
  Serial.begin(9600);
  //Serial1.begin(9600);
   mlx.begin(); }
void loop()
{
  mlx.begin(); 
   float body=(mlx.readObjectTempC()+1.99);
Serial.print("Ambient="); 
Serial.print(mlx.readAmbientTempC()); 
Serial.print("----BODY TemperaturE=");
Serial.print(mlx.readObjectTempC());// Serial.println("*C");
Serial.println("  ");
   int val=(map((mlx.readObjectTempC()),-70,382,0,122));
  } 
