/* This is a Cfunctions (version 0.28) generated header file.
   Cfunctions is a free program for extracting headers from C files.
   Get Cfunctions from 'http://www.lemoda.net/cfunctions/'. */

/* This file was generated with:
'cfunctions --backup -n -g ../include/SU_getpar atopkge.c docpkge.c ealloc1.c 
errpkge.c getpars.c strstuff.c subcalls.c' */
#ifndef GETPAR_H
#define GETPAR_H

/* From '../include/getpar.hin': */
#include <stdio.h>
#include <stddef.h>
/* From 'atopkge.c': */

#line 86 "atopkge.c"
short eatoh (char *s );

#line 98 "atopkge.c"
unsigned short eatou (char *s );

#line 110 "atopkge.c"
int eatoi (char *s );

#line 122 "atopkge.c"
unsigned int eatop (char *s );

#line 134 "atopkge.c"
long eatol (char *s );

#line 146 "atopkge.c"
unsigned long eatov (char *s );

#line 158 "atopkge.c"
float eatof (char *s );

#line 170 "atopkge.c"
double eatod (char *s );
/* From 'docpkge.c': */

#line 64 "docpkge.c"
extern int xargc;

#line 64 "docpkge.c"
extern char * * xargv;

#line 96 "docpkge.c"
void requestdoc (int flag );

#line 113 "docpkge.c"
void pagedoc (void);
/* From 'ealloc1.c': */

#line 21 "ealloc1.c"
void * ealloc1 (size_t n1 , size_t size );
/* From 'errpkge.c': */

#line 54 "errpkge.c"
void err (char *fmt , ... );

#line 71 "errpkge.c"
void warn (char *fmt , ... );

#line 87 "errpkge.c"
void syserr (char *fmt , ... );
/* From 'getpars.c': */

#line 157 "getpars.c"
void initargs (int argc , char **argv );

#line 175 "getpars.c"
int getparint (char *name , int *ptr );

#line 179 "getpars.c"
int getparuint (char *name , unsigned int *ptr );

#line 183 "getpars.c"
int getparshort (char *name , short *ptr );

#line 187 "getpars.c"
int getparushort (char *name , unsigned short *ptr );

#line 191 "getpars.c"
int getparlong (char *name , long *ptr );

#line 195 "getpars.c"
int getparulong (char *name , unsigned long *ptr );

#line 199 "getpars.c"
int getparfloat (char *name , float *ptr );

#line 203 "getpars.c"
int getpardouble (char *name , double *ptr );

#line 207 "getpars.c"
int getparstring (char *name , char **ptr );

#line 211 "getpars.c"
int getparstringarray (char *name , char **ptr );

#line 215 "getpars.c"
int getpar (char *name , char *type , void *ptr );

#line 221 "getpars.c"
int getnparint (int n , char *name , int *ptr );

#line 225 "getpars.c"
int getnparuint (int n , char *name , unsigned int *ptr );

#line 229 "getpars.c"
int getnparshort (int n , char *name , short *ptr );

#line 233 "getpars.c"
int getnparushort (int n , char *name , unsigned short *ptr );

#line 237 "getpars.c"
int getnparlong (int n , char *name , long *ptr );

#line 241 "getpars.c"
int getnparulong (int n , char *name , unsigned long *ptr );

#line 245 "getpars.c"
int getnparfloat (int n , char *name , float *ptr );

#line 249 "getpars.c"
int getnpardouble (int n , char *name , double *ptr );

#line 253 "getpars.c"
int getnparstring (int n , char *name , char **ptr );

#line 257 "getpars.c"
int getnparstringarray (int n , char *name , char **ptr );

#line 261 "getpars.c"
int getnpar (int n , char *name , char *type , void *ptr );

#line 365 "getpars.c"
void checkpars (void);

#line 402 "getpars.c"
int countparname (char *name );

#line 414 "getpars.c"
int countnparval (int n , char *name );

#line 428 "getpars.c"
int countparval (char *name );

#line 697 "getpars.c"
int getargtbl (char *name[] , char *asciival[] , int size );
/* From 'strstuff.c': */

#line 26 "strstuff.c"
void strchop (char *s , char *t );
/* From 'subcalls.c': */

#line 114 "subcalls.c"
FILE * efopen (const char *file , const char *mode );

#line 125 "subcalls.c"
int efclose (FILE *stream );

#line 136 "subcalls.c"
int efseek (FILE *stream , off_t offset , int origin );

#line 145 "subcalls.c"
off_t eftello (FILE *streem );

#line 160 "subcalls.c"
size_t efread (void *bufptr , size_t size , size_t count , FILE *stream );

#endif /* GETPAR_H */
