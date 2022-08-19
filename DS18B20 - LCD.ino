//INSTALL LIBRARY
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//DS18B20 sensor pin (free to replace)
#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

//Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,16,2);  

//Define variables
float celcius=0;
float farenheit=0;

//DS18B20 sensor
void temp()
{
  sensors.requestTemperatures(); 
  celcius=sensors.getTempCByIndex(0);
  fahrenheit=sensors.toFahrenheit(celcius);
}

void setup()
{
  sensors.begin();
  lcd.begin(); //lcd.init
  lcd.backlight(); //Turns backlight on
}

void loop()
{  
  temp();

  lcd.setCursor (0, 0 );
  lcd.print("Celcius: ");
  lcd.print(celcius);
  lcd.setCursor (0, 1 );
  lcd.print("Farenheit: ");  
  lcd.print(farenheit);
  
  delay(1000);  
}