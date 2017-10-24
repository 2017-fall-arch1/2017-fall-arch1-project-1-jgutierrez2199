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
void bstFree(struct bst *bstp);

/* add a string to the tree then rebalance it */
void bstPut(struct bstNode *node, char *s);

/*Wrapper for recursive node printing*/
void bstPrint(struct bst *bstp, char *msg);

/*recursive in order printing function*/
void nodePrint(struct bstNode *bp);

/*Gives the height recursively*/
int height(struct bstNode *bstp);

/*performs a right rotation to preserve balance*/
struct bstNode *rightRotate(struct bstNode *y);

/*performs a left rotation to preserve balance*/
struct bstNode *leftRotate(struct bstNode *x);

/*gives the balance number to determine which rotations to perform to balance it*/
int getBalance(struct bstNode *N);

/*jsut gives the max of two ints*/
int max(int a, int b);

/* Delete all elements off of the tree */
void bstMakeEmpty(bst *bstp);

/* print tree contents in order.  Prints default mesage if message is NULL */
void bstPrint(bst *bstp, char *msg);

#endif	/* included */
