

#include <kernel.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

char USER1[] = "user1";
char PASS1[] = "pass1";
char USER2[] = "user2";
char PASS2[] = "pass2";

local chat(ushort, ushort, char *name);

command xsh_chat(ushort stdin, ushort stdout, ushort stderr, ushort nargs, char * args[]){

	char username[20];
	char password[20];

	int log_status = 0;

	do{
		fprintf(stdout, "\nUsername: ");
		read(stdin, username, 20);

		fprintf(stdout, "Password: ");
		read(stdin, password, 20);

		if((strncmp(username, USER1, 5) == 0 &&
		    strncmp(password, PASS1, 5) == 0) ||
		   (strncmp(username, USER2, 5) == 0 &&
		    strncmp(password, PASS2, 5) == 0)){

			username[5] = '\0';
			fprintf(stdout, "\nWelcome back %s\n\n", username);
	         	log_status = 1; 
		}
		else{
			fprintf(stdout,"\n Incorrect Username/password");
			fprintf(stdout,"Please try again!\n");
		}
	} while(log_status == 0);

	if(stdin == TTY0)
		chat(TTY0, TTY1, username);
	else if(stdin == TTY1)
		chat(TTY1, TTY0, username);

	return OK;

}

local chat(ushort in, ushort out, char *name){

	char message[255];
	int i;
	int exit = 0;

	while(exit == 0){
		for( i = 0; i < 255; i++){
			message[i] = '\0';
		}

		read(in, message, 255);

		if(strncmp(message, "exit", 4) == 0){
			exit = 1;
			strcpy(message, "** LEFT THE CHAT **");
		}

		fprintf(out, "\x1B[31m" "%s: " "\033[0m", name);
		write(out, message, strlen(message));

	}

	return OK;
}
