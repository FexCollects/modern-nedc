#include <stdio.h>
#include <string.h>

#include "portable.h"

int fopen_s(FILE ** f, char *name, char *spec)
{
	if(f==NULL)
		return 1;
	*f=fopen(name,spec);
	if(*f==NULL)
		return 1;
	else
		return 0;

}
