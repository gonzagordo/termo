#include <control.h>
#include <configuracion.h>
#include <DallasTemperature.h>

bool termostato(DT *sensors,Dir sonda_termo,Dir sonda_exterior,float histeresis,float error)

{

bool sondas_correctas = true;

float temperatura_termo,temperatura_radiador,salto_termico;
sensors->requestTemperatures();
temperatura_radiador = sensors->getTempC(sonda_exterior);
temperatura_termo = sensors->getTempC(sonda_termo);

    if (sondas_correctas)
    {
        
     salto_termico = temperatura_radiador-temperatura_termo;

     //solo debug
    Serial.println(" salto termico ") ;
    Serial.println(salto_termico);
    //solo debug



        if (salto_termico>histeresis) 
        {
            Serial.println("enciende bomba");
            digitalWrite(built_in_pin,HIGH);

        }
        if (salto_termico<error)
        {
            Serial.println("apaga bomba");
            digitalWrite(built_in_pin,LOW);

        } 
    }


//debug only
Serial.print(" Temperatura termo: ");
Serial.print(temperatura_termo);

Serial.print(" Temperatura radiador : ");
Serial.print(temperatura_radiador);
Serial.println(" ");
//debug only
return 0;

}