# CPU_Inbygga_System

/********************************************************************************
* README.md
********************************************************************************/
Projektets kod ska emulera en 32-bitars CPU programmerad i C eller C++ som 
innehåller följande delar:

 - Interna minnen
 - Egenskapad instruktionslista
 - Dataminne
 - Programminne
 - stacken

CPUn ska implementeras på en Arduino UNO och det ska fungera att kunna läsa och 
skriva till digitala pinnar PORT A0 till PORT A19. PIN 0 till PIN 13 motsvarar
de digitala portarna på Arduino UNO (0-13), medan PORT A14 till PORT A19 
motsvarar de analoga portarna A0 till A5.

I/O-porten ska innehålla datariktningsregistret DDRA, dataregistret PORTA samt 
pinregistret PINA. PCI-avbrott ska kunna aktiveras för varje PIN genom en gemensam 
avbrottsrutin PCINT0_vect via ettställning av motsvarande bit i masregister PCMSKA.

/********************************************************************************
* Validering
********************************************************************************/
Validering av projektet ska ske genom att 3 lysdioder anslutna till PIN 8-PIN 13 
ska kunna togglas vid uppsläppning (Fallande flank) av var sin tryckknapp 
anslutna till PIN 11 - PIN 13 via PCI-avbrott.