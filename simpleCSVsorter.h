#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>
typedef struct rowLine{
	char* wholeLine;
	char* compareCat;
	struct rowLine *next;
}line;
