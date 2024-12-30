#include "log.h"

#include <stdarg.h>

#include "compat.h"

#define MAX_LOG_STR 256

int verbose;
FILE* ne_log;

void log_write(char* str, ...)
{
	char tmpstr[MAX_LOG_STR];
	va_list args;
	va_start(args,str);
	vsprintf_s(tmpstr,MAX_LOG_STR-1,str,args);
	va_end(args);
	if(verbose==1)
		printf("%s", tmpstr);
	if(ne_log!=NULL)
		fprintf(ne_log, "%s", tmpstr);
}

void log_only_write(char* str, ...)
{
	char tmpstr[MAX_LOG_STR];
	va_list args;
	va_start(args,str);
	vsprintf_s(tmpstr,MAX_LOG_STR-1,str,args);
	va_end(args);
	if(ne_log!=NULL)
		fprintf(ne_log, "%s", tmpstr);
}
