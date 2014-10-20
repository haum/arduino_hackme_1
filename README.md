Challenge Hackme pour Arduino Uno
=================================

Description
-----------
Il s'agit de l'adaptation pour Arduino Uno d'un Challenge proposé par JackDesBwa (l'adaptation n'est pas encore pleinement fonctionnelle, mais devrait suffire pour atteindre les objectifs de ce challenge)

::
  
  Matériel :
  - Une carte avec microcontrôleur ATMEGA32 (avec une liaison série et une
  led)
  - Un PC avec liaison série
  
  Objectif :
  En dialoguant par liaison série, trouver et exploiter une faille présente
  dans le firmware pour exécuter un code personnel faisant clignoter la led.
  
  Précision:
  Lecture du code source autorisé.



Prérequis
---------
Pour construire ce projet il est fait usage d'un fichier Makefile plutot que de l'environement arduino, même si le projet doit compiler dans celui ci.
En plus du Makefile disponible dans les fichiers et a adapter a votre environement de travail vous il faut installer [Arduino-Makefile](https://github.com/sudar/Arduino-Makefile)
L'IDE arduino v1.0.6 a été testé et fonctionne compile correctement le code source de ce projet.

  - [Version Windows](http://downloads.arduino.cc/arduino-1.0.6-windows.exe)
  - [Version Linux x86](http://downloads.arduino.cc/arduino-1.0.6-linux32.tgz)
  - [Version Linux x64](http://downloads.arduino.cc/arduino-1.0.6-linux64.tgz)


Utilisation
-----------
make clean && make upload && make monitor






Adaptation pour Arduino d'un Hackme proposé par JackDesBwa
