#ifndef __PASSWORD_MANAGER_H 
#define __PASSWORD_MANAGER_H

#include <stdint.h>
#include <avr/boot.h>

// Password validation return codes
#define PASSWORD_VALID		1
#define PASSWORD_INVALID	0

#define MAX_PASSWORD_LENGTH	10

// Public functions prototypes
int is_valid_password(const char *password);
// This function writes in flash memory so it must be in the 
// bootloader section
void change_password(const char *password); //BOOTLOADER_SECTION; 

#endif /* __PASSWORD_MANAGER_H */
