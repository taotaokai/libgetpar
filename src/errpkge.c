/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.                       */

/*********************** self documentation **********************/
/**************************************************************************
ERRPKGE - routines for reporting errors

err	print warning on application program error and die
warn	print warning on application program error
syserr	print warning on application program error using errno and die

***************************************************************************
Function Prototypes:
void err (char *fmt, ...);
void warn (char *fmt, ...);
void syserr (char *fmt, ...);

***************************************************************************
Return: void

***************************************************************************
Notes:
fmt		a printf format string ("\n" not needed)
...		the variables referenced in the format string

Examples:
	err("Cannot divide %f by %f", x, y);
	warn("fmax = %f exceeds half nyquist= %f", fmax, 0.25/dt);
 
	if (NULL == (fp = fopen(xargv[1], "r")))
 		err("can't open %s", xargv[1]);
 	...
 	if (-1 == close(fd))
 		err("close failed");

***************************************************************************
References:
Kernighan and Pike, "The UNIX Programming Environment", page 207.
Also Rochkind, "Advanced UNIX Programming", page 13.

***************************************************************************
Authors:SEP: Jeff Thorson, Stew Levin	CWP: Shuki Ronen, Jack Cohen
**************************************************************************/
/**************** end self doc ********************************/

#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>

#include "getpar.h"

void err(char *fmt, ...)
{
	va_list args;

 
	if (EOF == fflush(stdout)) {
		fprintf(stderr, "\nerr: fflush failed on stdout");
	}
	fprintf(stderr, "\n%s: ", xargv[0]);
	va_start(args,fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
	fprintf(stderr, "\n");
	exit(EXIT_FAILURE);
}


void warn(char *fmt, ...)
{
	va_list args;

	if (EOF == fflush(stdout)) {
		fprintf(stderr, "\nwarn: fflush failed on stdout");
	}
	fprintf(stderr, "\n%s: ", xargv[0]);
	va_start(args,fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
	fprintf(stderr, "\n");
	return;
}


void syserr(char *fmt, ...)
{
	va_list args;

	if (EOF == fflush(stdout)) {
		fprintf(stderr, "\nsyserr: fflush failed on stdout");
	}
	fprintf(stderr, "\n%s: ", xargv[0]);
	va_start(args,fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
	fprintf(stderr, " (%s)\n", strerror(errno));
	exit(EXIT_FAILURE);
}
