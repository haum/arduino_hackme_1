#include "Arduino.h"
#include "ui.h"
#include "password_manager.h"

#include "common.h"

// Private global variables


// Private functions prototypes
void display_user_mode_banner();
void display_admin_mode_banner();

/* PUBLIC FUNCTIONS */

void user_mode() {
	char password[MAX_PASSWORD_LENGTH+1];
	char input_character;
	int i;
	
	display_user_mode_banner();
	Serial.println("Please enter ADMIN mode password and press <ENTER>");
	
	// Get user password
	//while(uart_receive((uint8_t*)&input_character) != UART_SUCCESS);
	while (Serial.available() <= 0); 
	
	input_character = Serial.read();

	for(i=0; input_character != CR; i++) {
		Serial.print('*');
		password[i] = input_character;
		while (Serial.available() <= 0); 
		input_character = Serial.read();
	}
	// Null terminate password
	password[i] = '\0';
	
	if(is_valid_password(password)) {
		admin_mode();
	}
	else {
		Serial.println("");
		Serial.println("Wrong password");
	}

}
 
void admin_mode() {
	char chosen_option;

	display_admin_mode_banner();

	while(1) {
		Serial.println("Please choose one of the following options");
		Serial.println("(1) Change the ADMIN password");
		Serial.println("(2) Quit");

		// Get option from user
	
		while (Serial.available() <= 0); 
		chosen_option = Serial.read();
		// Show chosen option
		//Serial.println("");

	
		if(chosen_option == '1') {
			Serial.println("New password : ");

			// Get new password
			char password[MAX_PASSWORD_LENGTH+1];
			char input_character;
			uint8_t i;

			while (Serial.available() <= 0); 
			input_character = Serial.read();
			for(i=0; input_character != CR && i<MAX_PASSWORD_LENGTH; i++) {
				// Send feedback
				password[i] = input_character;
				while (Serial.available() <= 0); 
				input_character = Serial.read();
			}
			//Serial.println("");
			// Null terminate password
			password[i] = '\0';

			change_password(password);
		}
		else if(chosen_option == '2') {
			break;
		}
		else {
			Serial.println("Invalid option. Please try again");
		}
	}
}

/* PRIVATE FUNCTIONS */

void display_user_mode_banner() {
	Serial.println("");
	Serial.println("Welcome in USER mode.");
	Serial.println("");
	Serial.println("");
}

void display_admin_mode_banner() {
	Serial.println("");
	Serial.println("Welcome in ADMIN mode.");
	Serial.println("");
	Serial.println("");
}
