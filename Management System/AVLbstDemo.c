#include <stdio.h>		/* for printf */
#include <stdlib.h>		/* for free() */
#include <string.h> 		/* for strlen */
#include "AVLbst.h"		/* for bst and balancing operations */


/* read no more than limit chars into s, return #chars read.  Doesn't include trailing \n */
int gets_n(char *s, int limit)	
{
  char *p = s;			/* for indexing into s */
  char c;
  if (fgets(s, limit, stdin)) {
    while ((c = *p) && c != '\n') /* scan p through s until 0 or \n */
      p++;
    if (c == '\n')		/* erase \n */
      *p = 0;
  }
  return (p - s);		/* #chars read (not including terminator or \n*/
}

int main()
{
  char buf[100];
  bst *bstp = bstAlloc();	/* make empty tree */

  bstPrint(bstp, "Tree contents, prior to reading input:");

  while (gets_n(buf, 100)){	/* build tree rebalancing along the way */
    bstPut(bstp.root, buf);
  }
  
  bstPrint(bstp, "Tree contents, after building tree:");

  //FIXME add in insertion, deletion, and search capability here
  
  bstFree(bstp);//cleans up after the party

  return 0;
}
