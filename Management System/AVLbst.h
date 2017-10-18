#ifndef AVLbst_included		/* prevent multiple inclusion */
#define AVLbst_included


/* a binary search tree node */
typedef struct bstNode {
  struct bstNode *left;
  struct bstNode *right;
  char *str;
  int height;
} node;

/* a bst tree */
typedef struct bst {
  bstNode *root;
} tree;

/* create a new tree */
bst *bstAlloc();

/* free memory associated with a tree, discarding all items it contains */
void bstFree(bst *bstp);

/* add a string to the tree then rebalance it */
void bstPut(bst *bstp, char *s);

/* Delete all elements off of the tree */
void bstMakeEmpty(bst *bstp);

/* print tree contents in order.  Prints default mesage if message is NULL */
void bstPrint(bst *bstp, char *msg);

#endif	/* included */
