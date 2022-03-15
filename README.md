# microclimate-control-arduino

Versión original

Código de arduino: v1-controlfan.ino
Simulación en Proteus: control-temp.pdsprj

La versión original enciende o apaga un ventilador dependiendo de las condiciones de temperatura y humedad relativa fijadas. Los valores de las variables 
se muestran en un terminal virtual.

Versión 2

Código de arduino: microclimate-control-edit1.ino
Simulación en Proteus: microclimate-control-edit1.pdsprj

En la versión 2 se agregaron una bomba de agua y una lámpara (ambos simulados con un led) que se encienden o apagan junto con el ventilador dependiendo de las condiciones
de temperatura y humedad relativa fijadas. Además, se agregó una lcd para imprimir los valores de las variables. 

Versión 3: 

Código de arduino: code-microclimate-control-edit2.ino
Simulación en Proteus: sim-microclimate-control-edit2.pdsprj
Aplicación: app-microclimate-control-edit2.aia

En la versión 3 se construyó una app (con MIT App Inventor) de lectura de los datos conectada mediante un módulo bluetooth. En el código y simulación se agregó el módulo para hacer
la conexión. 

Versión 4: 

Se agregan dos funcionalidades al proyecto inicial con Arduino.
  1. Alarma para cuando la cosecha del invernadero esté lista.
  2. Alarma para cuando los valores de luminosidad o radiación solar se sobrepasan de un límite ya fijo.

Primera funcionalidad:
  **MPLABX-Func1** código en MP LAB X con el compilador pic-as
  
  
  **luminosidad-as** archivo para implementar el código de la primera funcionalidad

Segunda funcionalidad:
  **MPLABX-Func2** código en MP LAB X con el compilador XC8 
  
  
  **Timer0-COSECHA** archivo para implementar el código de la segunda funcionalidad
