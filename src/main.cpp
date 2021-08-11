#include <Arduino.h>
//incluye las librerias necesarias
#include <OneWire.h>
#include <DallasTemperature.h>
#include <configuracion.h>
#include <debug.h>
#include <control.h>
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>

// Constructor de la librería de LCD 16x2
// Aqui se configuran los pines asignados a la pantalla del PCF8574
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);



// se crea una instancia del controlador de comunicacion onewire
OneWire canal_oneWire(ONE_WIRE_PIN);

// pasamos referencia del contolador de comunicacion al driver del sensor 
DT sensors(&canal_oneWire);

// asignacion de las direcciones de los sensores 
Dir termometro_exterior = sensor_10m;
Dir termometro_interior_1m = sensor_1m ;
Dir termometro_interior_2m = sensor_2m ;


/*
 * rutina inicial de configuracion
 */
void setup(void)
{
  //inicializa display
  lcd.begin(16, 2);
  // Mover el cursor a la primera posición de la pantalla (0, 0)
  lcd.home ();
  // Imprimir "Hola Mundo" en la primera linea
  lcd.print("sensores");

  //se inicializa la salida de control del rele de la bomba 
  pinMode(built_in_pin,OUTPUT);
  


  // inicializa puerto serie
  Serial.begin(9600);
  Serial.println("lector de tres sensores pero conectados 2 ");

  // localiza sensores en el bus 
  Serial.print("localizando dispositivos...");
  sensors.begin();
  Serial.print("encontrados  ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" dispositivos.");

  // informa sobre el modo de energia del bus
  Serial.print("el modo parasito esta en: "); 
  if (sensors.isParasitePowerMode()) Serial.println("ON");
  else Serial.println("OFF");
  
  
  
  Serial.print("Device 0 Address: ");
  printAddress(termometro_exterior);
  Serial.println();
  Serial.print("Device 1 Address: ");
  printAddress(termometro_interior_1m);
  Serial.println();

  // set the resolution to 9 bit (Each Dallas/Maxim device is capable of several different resolutions)
  sensors.setResolution(termometro_exterior, 9);
  sensors.setResolution(termometro_interior_1m, 9);

  Serial.print("Device 0 Resolution: ");
  Serial.print(sensors.getResolution(termometro_exterior), DEC); 
  Serial.println();

  Serial.print("Device 1 Resolution: ");
  Serial.print(sensors.getResolution(termometro_interior_1m), DEC); 
  Serial.println();
}




/*
 * bucle principal
 */
void loop(void)
{ 
  
  bool caca = termostato(&sensors,termometro_interior_1m,termometro_interior_2m,5,2);

  
  
  delay(2000);
  
}

