#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "getpar.h"

char *sdoc[] = {
" 									",
" Test - test for SU getpar utility",
" 									",
" sucddecon <stdin >stdout [optional parameters]			",
" 									",
" Required parameters:							",
" filter= 		ascii filter values separated by commas		",
" 									",
NULL};

int main(int argc, char **argv)
{
	int i;

	char *srcfile;
	char *datfile;
	float b,e,k,a;
	int nv; float *v;

	/* Initialize */
	initargs(argc, argv);
	requestdoc(1);

	/* Get parameters */
	if (!getparstring("src", &srcfile)) err("must specify src= source file");
	if (!getparstring("dat", &datfile)) err("must specify dat= data file");
	if (!getparfloat("b", &b)) b=-INFINITY;
	if (!getparfloat("e", &e)) e=INFINITY;
	if (!getparfloat("k", &k)) k=0.01;
	if (!getparfloat("a", &a)) a=0;
	if ((nv=countparval("v"))) {
		v=malloc(nv*sizeof(float));
		getparfloat("v",v);
	}

	/* Print out parameters */
	printf("src=%s dat=%s b=%f e=%f k=%f a=%f v=",srcfile,datfile,b,e,k,a);
	for (i=0;i<nv;i++) printf("%f,",v[i]);
	printf("\n");

	return 0;
}
