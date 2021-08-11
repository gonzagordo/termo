#if !defined(debug_h)
#define debug_h

//#include <OneWire.h>
#include <configuracion.h>
#include <DallasTemperature.h>


//imprime la direccion seleccionada pues es un array 
void printAddress(Dir deviceAddress); 

//imprime la temperatura del dispositivo seleccionado en Cº y Fº
void printTemperature(Dir deviceAddress,DT sensors,bool farenheit = false);





#endif // debug_h

