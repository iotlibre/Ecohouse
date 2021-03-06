
#ifndef power_sensor_h
#define power_sensor_h

// *******************************************************
// ******** CONFIGURACION SENSORES DE POTENCIA    ********
// *******************************************************

// 97.6  66.5  51.3  20.0

#define NUMBER_OF_PWR_SENSORS 6
#define TRANSFORMATOR_CONSTANT 20.0

#define MAME_PWR_1 "p1"
#define ENTER_1 A0
#define CURRENT_CONST_1 TRANSFORMATOR_CONSTANT

#define MAME_PWR_2 "p2"
#define ENTER_2 A1
#define CURRENT_CONST_2 TRANSFORMATOR_CONSTANT

#define MAME_PWR_3 "p3"
#define ENTER_3 A2
#define CURRENT_CONST_3 TRANSFORMATOR_CONSTANT

#define MAME_PWR_4 "p4"
#define ENTER_4 A3
#define CURRENT_CONST_4 TRANSFORMATOR_CONSTANT

#define MAME_PWR_5 "p7"
#define ENTER_5 A6
#define CURRENT_CONST_5 TRANSFORMATOR_CONSTANT

#define MAME_PWR_6 "p8"
#define ENTER_6 A7
#define CURRENT_CONST_6 TRANSFORMATOR_CONSTANT


// *******************************************************

#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;

// variable declaration

String name_pwr[]=
  {
    MAME_PWR_1,
    MAME_PWR_2,
    MAME_PWR_3,
    MAME_PWR_4,
    MAME_PWR_5,
    MAME_PWR_6
  };

int enter_pin[]=
  {
    ENTER_1,
    ENTER_2,
    ENTER_3,
    ENTER_4,
    ENTER_5,
    ENTER_6
  };

float current_const[]=
  {
    CURRENT_CONST_1,
    CURRENT_CONST_2,
    CURRENT_CONST_3,
    CURRENT_CONST_4,
    CURRENT_CONST_5,
    CURRENT_CONST_6
  }; 

// Function Prototypes
void buildPowerMessage(uint8_t);


void buildPowerMessage(uint8_t output)
  {
    for (uint8_t i=0; i < NUMBER_OF_PWR_SENSORS; i++)
      {      
        emon1.current(enter_pin[i],current_const[i]);      // Current: input pin, calibration.

        for (uint8_t i=0; i<9; i++)
          {
            double Irms = emon1.calcIrms(1480);  // Calculate Irms only
          }
        
        double Irms = emon1.calcIrms(1480);
        double Pwr=(Irms*230.0); 
      
        String value_pwr = String(Pwr,2);    
        if (output==0) 
          {

            Serial.println("wifiSerialInit.println");
            Serial.println (name_pwr[i] + ":" + value_pwr);
            wifiSerialInit.println (name_pwr[i] + ":" + value_pwr);
          }
        if (output==1) 
          {
            Serial.println("wifiSerialInit.println");
            Serial.println (name_pwr[i] + ":" + value_pwr);

          }
      }
  }

#endif
