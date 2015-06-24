/* Modified for use of getpars only. tao,20140828 */

/*****************************************************************************/
/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.                       */
/*****************************************************************************/

/*****************************************************************************
Author: Jack Cohen, Center for Wave Phenomena
Zhaobo Meng added 4d (except ealloc4), 5d and 6d functions
*****************************************************************************/

#include <stdlib.h>

#include "getpar.h"

#define ERROR	NULL

/* allocate a 1-d array */
void *ealloc1 (size_t n1, size_t size)
{
	void *p;

	if (ERROR == (p=malloc(n1*size)))
		syserr("%s: malloc failed", __FILE__);
	return p;
}
