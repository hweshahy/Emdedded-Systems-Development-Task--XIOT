# Emdedded-Systems-Development-Task--XIOT
Instructions to setup the application:

1- Compiling:
      
      a- Install Atmel Studio 7.0
      
      b- select on open project
      
      c- select "Embedded_Task_XIOT.atsln" from the folder called "Embedded_Task_XIOT"

2- simulatuion and testing:
      
      a- Install proteus 7.7 professional
      
      b- select open design
      
      c- select "Embedded_Task_XIOT.DSN" from "simulation"
      
      d- double click on the atmega32 on the schematic
      
      e- in program file field select "Embedded_Task_XIOT.hex" from "simulation"
      
      f- click on run button
      
3- loading the code
      
      a- install Khazama AVR Burner 
      
      b- connect the burner to the computer with a USB cable
      
      c- Install the driver manually from "C:\Program Files\khazama.com\Khazama AVR Programmer\win-driver\libusb_0.1.12.1"
      
      d- install extreme AVR burner
      
      e- click on open then select "Embedded_Task_XIOT.hex" from "Embedded_Task_XIOT/Embedded_Task_XIOT/Debug"


Assumptions:

      1- I am working on ATMega32 micro-controller.

      2- I assumed that the monitor is a (16x2) LCD.

      3- There isn’t nested interrupts.

      4- Using UART for sending serial data.

      5- Operating frequency= 8MHz, so I calculated the required value for the timer to have the 3 seconds.

      6- The data temperature range is (0-100) and using ADC of 10 bits to sense the temperature.

Issues:

      1- Using long interrupt handler may cause problems as it stops other tasks.

      2- Using polling system it will cause system delay and losing cycles.

      3- If anybody is fast enough to press the switch too fast, the systems won’t work as designed as it won’t sense it.
