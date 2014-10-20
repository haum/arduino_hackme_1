#include "password_manager.h"
#include "common.h"
#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

// Address must be in byte
#define FLASH_MEMORY_PAGE_ADDRESS	0x1600

// Password Magic
// Use this to see if a valid password is stored in flash
#define PASSWORD_MAGIC			0x00AA
#define PASSWORD_MAGIC_LENGTH	2

// Private global variables
static char *default_admin_password = "admin";

/* PUBLIC FUNCTIONS */

int is_valid_password(const char *password) {
	uint8_t ret_val = PASSWORD_INVALID;

	uint8_t *mem_ptr = (uint8_t *)FLASH_MEMORY_PAGE_ADDRESS;

	// Check if there is a valid password stored in flash
	if((pgm_read_byte(mem_ptr) | (pgm_read_byte((mem_ptr+1)) << 8))
			== PASSWORD_MAGIC) {
		mem_ptr += PASSWORD_MAGIC_LENGTH;
		char admin_password_char = pgm_read_byte(mem_ptr++);
		for(uint8_t i=0; password[i] == admin_password_char; i++, mem_ptr++) {
			if(admin_password_char == '\0') {
				ret_val = PASSWORD_VALID;
				break;
			}
			admin_password_char = pgm_read_byte(mem_ptr);
		}
	}
	// Use default password
	else {
		for(uint8_t i=0; password[i] == default_admin_password[i]; i++) {
			if(default_admin_password[i] == '\0') {
				ret_val = PASSWORD_VALID;
				break;
			}
		}
	}
	return ret_val;
}

void change_password(const char *password) {
	uint8_t temp;
	uint8_t i = 0;

	temp = SREG;
	cli();

	// Ref: http://www.nongnu.org/avr-libc/user-manual/group__avr__boot.html
	boot_page_erase(FLASH_MEMORY_PAGE_ADDRESS);
    boot_spm_busy_wait();      // Wait until the memory is erased.

	// Add the magic at the beginning
	boot_page_fill(FLASH_MEMORY_PAGE_ADDRESS + i, PASSWORD_MAGIC);
	i+=PASSWORD_MAGIC_LENGTH;

    for(; i<(PASSWORD_MAGIC_LENGTH+MAX_PASSWORD_LENGTH+1); i+=2) {
        // Set up little-endian word.

        uint16_t w = *password++;
        w += (*password++) << 8;
    
        boot_page_fill(FLASH_MEMORY_PAGE_ADDRESS + i, w);

		// Quit if last written word contain the null character
		if(*(password-1) == '\0' || *(password-2) == '\0') {
			break;
		}
    }

    boot_page_write(FLASH_MEMORY_PAGE_ADDRESS);     // Store buffer in flash page.
    boot_spm_busy_wait();       // Wait until the memory is written.

	// Reenable RWW-section again. We need this if we want to jump back
    // to the application after bootloading.
	boot_rww_enable ();

	// Set back the global interrupt bit to its original state
	SREG |= temp & (1<<SREG_I);
}
