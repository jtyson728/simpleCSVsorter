#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>

#ifndef SIMPLECSVSORTER_H
#define SIMPLECSVSORTER_H

typedef struct rowLine{
	char* wholeLine;
	char* compareCat;
	struct rowLine *next;
}line;

int commaCounter(char*, char*, int);


#endif
