
#if !defined(configuracion_h)
#define configuracion_h

// numero del pin al que se conecta el sensor
#define ONE_WIRE_PIN 10
// builtin pin 
#define built_in_pin 13


// direcciones actuales de los sensores con las medidas
#define sensor_1m   {0x28, 0xB3, 0x07, 0x55, 0x0B, 0x00, 0x00, 0x89}
#define sensor_2m   {0x28, 0x5B ,0x63 ,0x45 ,0x92 ,0x13 ,0x02 ,0x94}
#define sensor_10m  {0x28, 0x97, 0x0A, 0xAA, 0x1B, 0x19, 0x01, 0xAE}
#define DT DallasTemperature 
#define Dir DeviceAddress
 

#endif // configuracion_h





