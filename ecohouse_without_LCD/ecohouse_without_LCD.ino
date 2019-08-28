#define DEBUG 0

#define BPS 115200 //Velocidad de las comunicaciones

#include <SoftwareSerial.h>
#define RXPIN 6
#define TXPIN 5
SoftwareSerial wifiSerialInit (RXPIN,TXPIN);

#include "power_sensor.h"

uint32_t t_last_tx=0;
uint32_t t_last_lcd=0;

void setup(void)

  {     
     Serial.begin(BPS);
     wifiSerialInit.begin(BPS);
  }

void loop(void)
  {
    uint32_t current_time= millis();
    
    if ((current_time - t_last_tx) > 40000)
      {      
        Serial.print(F("******Print WIFI - sgs: "));
        t_last_tx = current_time;
        Serial.println(millis() / 1000);
        //buildTemperatureMessage(0);
        buildPowerMessage(0);
      }

    if ((current_time - t_last_lcd) > 20000)
      {     
        Serial.print(F("******Print LCD - sgs: "));
        t_last_lcd = current_time;
        Serial.println(millis() / 1000);
        //buildTemperatureMessage(1);
        buildPowerMessage(1);
      }

  }
  
