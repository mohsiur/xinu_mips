/**
 * @file xsh_pallindrome.c
 * @provide xsh_pallindrome
 *
 * $Id$
 *
 * Embedded XINU, Copyright (C) 2007. All rights reserved. */

#include <kernel.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * Shell command echos whether input text is pallindrome or nor to standord out
 * @param stdin descriptor of input device
 * @param stdout descriptor of output device
 * @param stderr descriptor of error device
 * @parram args array of arguments
 * @return OK for success, SYSERR for syntax error
 */

command xsh_pallindrome(ushort stdout, ushort stdin, ushort stderr, ushort nargs, char *args[]){
	int i;
	char S[255];
	char T[255];
	if((nargs == 2 && strncmp(args[1], "--help", 6) == 0) || (nargs == 1)){
		fprintf(stdout, "\tUsage:\tpallindrome [input_text] Yes = pallindrome, No = Not a pallindrome\n");
		fprintf(stdout, "\t--help\t display this help and exit\n");
		return SYSERR;
	}
	
	
	S[0] = '\0';

	for(i = 1; i < nargs; i++){
		strcat(S, args[i]);
		if( nargs > i+1) strcat( S, " ");
	}
	strcpy(T, S);
	strrev(T);
	if(strcmp(S, T) == 0) fprintf(stdout, "Yes\n");
	else fprintf(stdout, "No\n");

}


