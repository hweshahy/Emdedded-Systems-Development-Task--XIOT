# Emdedded-Systems-Development-Task--XIOT
Instructions to set it up on Sandbox:


Assumptions:

1-	I am working on ATMega32 micro-controller.

2-	I assumed that the monitor is a (16x2) LCD.

3-	There isn’t nested interrupts.

4-	Using UART for sending serial data.

5-	Operating frequency= 8MHz, so I calculated the required value for the timer to have the 3 seconds.

6-	The data temperature range is (0-100) and using ADC of 10 bits to sense the temperature.

Issues:

1-	Using long interrupt handler may cause problems as it stops other tasks.

2-	Using polling system it will cause system delay and losing cycles.

3-	If anybody is fast enough to press the switch too fast, the systems won’t work as designed as it won’t sense it.
