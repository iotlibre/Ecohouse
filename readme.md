# EcoHouse

Este kit de medida está pensado para tomar las medidas de consumo eléctrico de una vivienda o de un edificio con consumos inferiores a 10 KW. El sistema permite diferenciar varias zonas.
EcoHouse se puede instalar en el cuadro eléctrico principal o en cualquier otra parte  que nos permita tomar datos del consumo mediante pinzas (transformadores de intensidad). 
En el un edificio podemos tener tantos dispositivos como sean necesarios y el servidor EcoEficiencia los integrará en la misma instalación sin necesidad de configuraciones adicionales o cambios en el Firmware.
La comunicación se hace mediante Wifi por lo que no es necesario el cableado de datos al equipo solamente es necesario que esté dentro de la cobertura de la red WIFI del edificio. 
Para su uso no son necesarios conocimientos de informática aunque todos los desarrollos y el hardware están hechos bajo licencias libres lo que permite la modificación y mejora de las funcionalidades.

## Listado con las principales características
Las principales características de EcoBuilding son:
- 6 entradas para sensores de corriente con salida estandar de 50 mA o 1 Voltio
- Comunicación a Internet por WIFI local
- Configurable vía Web
- Display para mostrar el consumo instantáneo
- Alimentación a 220 voltios de corriente alterna
- Montaje en carril din
- Es posible configurar dos entradas analógicas adicionales pero en este caso el display permanecerá inoperativo
- La PCB integra un Arduino nano  con el ESP8266 12E
- Compatible con el [servidor de Open Energy Monitor](https://emoncms.org/)

## Montaje
El listado de componentes que has debido recibir es el siguientes:

- 1 PCB con los componentes de superficie ya montados
- 1 Carcasa para carril DIN
- 1 Tapa superior carcasa con display LCD 1602 y adaptador IIC/I2C
- 1 PCB Mesh building
- 1 Fuente de alimentación a 12 voltios
- 1 Arduino Nano
- 1 Integrado ESP8266 12E con el firmware mesh_building incluido
- 1 Convertidor DC-DC Step Down ajustable (salida 7,5V)
- 1 Regulador de tensión LM 1117
- 2 Conectores macho -hembra de 2.0mm para el ESP
- 2 Conectores macho hembra de 2.54mm para Arduino
- 2 Conectores macho hembra de 2.54mm para al display
- 9 Terminales de tornillo para PCB
- 2 Resistencias 10k 
- 3 Condensador 22uF
- 1 Condensador de 100nF
- 1 Diodo 1N4007

![ecohouse_componentes](docs/ecohouse_componentes.jpg)


