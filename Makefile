#ARDUINO_DIR = /home/rebrec/tools/electronique/arduino-1.0.5
#ARDUINO_DIR = /home/rebrec/tools/electronique/arduino-1.5.6-r2
ARDUINO_DIR = /home/rebrec/tools/electronique/arduino-1.0.6
ARDUINO_PORT = /dev/ttyUSB0
MONITOR_BAUDRATE = 9600
BOARD_TAG    = uno
#ARDUINO_LIBS = LiquidCrystal

AVRDUDE = $(ARDUINO_DIR)/hardware/tools/avrdude
AVRDUDE_CONF = $(ARDUINO_DIR)/hardware/tools/avrdude.conf


include /usr/share/arduino/Arduino.mk
