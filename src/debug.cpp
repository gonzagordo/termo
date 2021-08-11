#include <debug.h>
#include <DallasTemperature.h>


// function to print a device address
void printAddress(Dir deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}


// function to print the temperature for a device
void printTemperature(Dir deviceAddress , DT sensors, bool farenheit)
{
  
  float tempC = sensors.getTempC(deviceAddress);
  
  if(tempC == DEVICE_DISCONNECTED_C) 
  {
    Serial.println("Error: Could not read temperature data");
    return;
  }
  Serial.print(" Temp C: ");
  Serial.print(tempC);
  
  if (farenheit)
  {
  Serial.print(" Temp F: ");
  Serial.print(DT::toFahrenheit(tempC)); // Converts tempC to Fahrenheit
  }  
  Serial.println(" ");
}



// a modo de portapapeles escaneo de direcciones por index 
/*

  if (!sensors.getAddress(termometro_1, 0)) Serial.println("Unable to find address for Device 0"); 
  if (!sensors.getAddress(termometro_2, 1)) Serial.println("Unable to find address for Device 1"); 
  
*/

