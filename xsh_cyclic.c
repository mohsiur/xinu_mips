/**
 * @file xsh_cyclic.c
 * @provides xsh_cyclic
 *
 * $Id$
 */
/* Embedded XINU, Copyright (C) 2007. All rights reserved. */
#include <kernel.h>
#include <stdio.h>
#include <clock.h>
#include <cyclic.h>
/**
 * Shell command for showing a cyclic executive for the following table
 *
 * |ti|ri|ei|pi|Di|
 * |t1|0 |2 |4 |4 |
 * |t2|0 |1 |6 |6 |
 * |t3|0 |1 |12|12|
 *
 * Hyer Period = 12
 * Frame = 2
 *
 */

#define SLOTX 6
#define CYCLEX 2

command xsh_cyclic(ushort stdout, ushort stdin, ushort stderr, ushort nargs, char *args[]){
	int cycle =0, slot = 0;
	fprintf(stdout, "\n Starting a new Hyperperiod \n");
	for(slot = 0; slot < SLOTX; slot++){
		fprintf(stdout, "\n Starting a new frame \n");
		for(cycle = 0; cycle < CYCLEX; cycle++){
			(*ttable[slot][cycle])();
		}
	}
		
				
	
	return OK;
}
