#include <stdio.h>
#include <stdlib.h>
#include "getpar.h"

char *sdoc[] = {
"                                   ",
" GETARGTBL",
"                                   ",
" getargtbl <key>=<val> ...",
"                                   ",
NULL};

int main(int argc, char **argv)
{
  int i, npars;
  int parnum=100;
  char *name[100];
  char *asciival[100];

  /* Initialize */
  initargs(argc, argv);
  requestdoc(1);

  /* Get parameters */
  npars = getargtbl(name, asciival, parnum);

  /* Print out parameters */
  for (i=0; i<npars; i++) {
    printf("i=%d key=%s value=%s\n",i,name[i],asciival[i]);
  }

  return 0;
}
