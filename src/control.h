#if !defined(config_h)
#define config_h
#include <configuracion.h>
#include <DallasTemperature.h>
//termostato diferencial con histeresis programable
bool termostato(DT *sensors,Dir sonda_termo,Dir sonda_exterior,float histeresis,float error);


#endif // config_h
