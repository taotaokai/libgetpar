/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.                       */

/*********************** self documentation **********************/
/***************************************************************************
ATOPKGE - convert ascii to arithmetic and with error checking

 
eatoh		ascii to short
eatou		ascii to unsigned short
eatoi		ascii to int
eatop		ascii to unsigned
eatol		ascii to long
eatov		ascii to unsigned long
eatof		ascii to float
eatod		ascii to double

****************************************************************************
Function Prototypes:
short eatoh(char *s);
unsigned short eatou(char *s);
int eatoi(char *s);
unsigned int eatop(char *s);
long eatol(char *s);
unsigned long eatov(char *s);
float eatof(char *s);
double eatod(char *s);

****************************************************************************
Input:
s		string 

Returned:	type indicated
 
****************************************************************************
Notes:
Each of these routines acts like atoi, but has error checking:

This is a major revision of the tedious code required before
vendors implemented the ANSI C strtol, strtoul and strtod.

In addition to the size checks for each integer type, a
specific test on errno is required.  For example, INT_MAX
may (and probably does) equal LONG_MAX.  In this case,
if fed a number exceeding INT_MAX (and LONG_MAX), strtol
will make a quiet return with the wrong answer and it is up
to the user to check if errno == ERANGE.

Size limits are machine dependent and are read from the
ANSI C include files limits.h and float.h.

Bug Report: With NeXT c and Gnucc, when x > DBL_MAX (x <-DBL_MAX),
the return value from strtod was +Infinity (-Infinity), not HUGE_VAL
and more important, errno was not set to ERANGE.  To cope with this,
I put explicit size checks in eatod (which would not be needed if
errno were set as it should be in ANSI C.    jkc 01/29/94

On IBM RS6000, the return value from strtod was +-Inf on
overflow, but errno was set correctly.

****************************************************************************
References:
For old code:
Plum: Reliable Data Structures in C, p. 2-17.
Kernighan and Ritchie: The C Programming Language, p. 58.

CWP: Jack K. Cohen, Brian Sumner
 
For new code:
ANSI C routines with a little help from Jack

****************************************************************************
Author: Jack Cohen, Center for Wave Phenomena, 1994.
***************************************************************************/
/**************** end self doc ********************************/

#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <float.h>

#include "getpar.h"

/* eatoh - convert string s to short integer {SHRT_MIN:SHRT_MAX} */
short eatoh(char *s)
{
	long n = strtol(s, NULL, 10);
	
	if ( (n > SHRT_MAX) || (n < SHRT_MIN) || (errno == ERANGE) )
		err("%s: eatoh: overflow", __FILE__);

	return (short) n;
}


/* eatou - convert string s to unsigned short integer {0:USHRT_MAX} */
unsigned short eatou(char *s)
{
	unsigned long n = strtoul(s, NULL, 10);

	if ( (n > USHRT_MAX) || (errno == ERANGE) )
		err("%s: eatou: overflow", __FILE__);

	return (unsigned short) n;
}


/* eatoi - convert string s to integer {INT_MIN:INT_MAX} */
int eatoi(char *s)
{
	long n = strtol(s, NULL, 10);

	if ( (n > INT_MAX) || (n < INT_MIN) || (errno == ERANGE) )
		err("%s: eatoi: overflow", __FILE__);

	return (int) n;
}


/* eatop - convert string s to unsigned integer {0:UINT_MAX} */
unsigned int eatop(char *s)
{
	unsigned long n = strtoul(s, NULL, 10);

	if ( (n > UINT_MAX) || (errno == ERANGE) )
		err("%s: eatop: overflow", __FILE__);

	return (unsigned int) n;
}


/* eatol - convert string s to long integer {LONG_MIN:LONG_MAX} */
long eatol(char *s)
{
	long n = strtol(s, NULL, 10);

	if (errno == ERANGE)
		err("%s: eatol: overflow", __FILE__);

	return n;
}


/* eatov - convert string s to unsigned long {0:ULONG_MAX} */
unsigned long eatov(char *s)
{
	unsigned long n = strtoul(s, NULL, 10);

	if (errno == ERANGE)
		err("%s: eatov: overflow", __FILE__);

	return n;
}


/* eatof - convert string s to float {-FLT_MAX:FLT_MAX} */
float eatof(char *s)
{
	float x = strtod(s, NULL);

	if ( (x > FLT_MAX) || (x < -FLT_MAX) || (errno == ERANGE) )
		err("%s: eatof: overflow", __FILE__);

	return (float) x;
}


/* eatod - convert string s to double {-DBL_MAX:DBL_MAX} */
double eatod(char *s)
{
	double x = strtod(s, NULL);

	/* errno == ERANGE suffices if compiler sets errno on overflow */
	if ( (errno == ERANGE) || (x > DBL_MAX) || (x < -DBL_MAX) )
		err("%s: eatod: overflow", __FILE__);

	return x;
}
