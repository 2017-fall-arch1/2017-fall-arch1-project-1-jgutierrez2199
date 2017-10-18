
#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include "AVLbst.h"		


/* create a new tree */
bst *bstAlloc()
{
  bst *bstp = (struct bst *)malloc(sizeof(bst));
  bstp.root = 0;
  return bstp;
}

/* recycle a tree */
void bstFree(struct bst *bstp)
{
  free(bstp);
}
  
/* append a copy of str to bst and balance must be handed a node not full tree for recursion to work */
struct bstNode *bstPut(struct bstNode *node, char *s){

  int len;
  char *scopy;

  for (len = 0; s[len]; len++) /* compute length */
    ;
  scopy = (char *)malloc(len+1);
  for (len = 0; s[len]; len++) /* copy chars */
    scopy[len] = s[len];
    scopy[len] = 0;			/* terminate copy */

  /*normal insertion */
  if(node== NULL){
    struct bstNode *newNode = (struct bstNode *)malloc(sizeof(bstNode));
    bstp.root = newNode;
    return(bstp);
  }
  if (strcmp(s, node.str) < 0){
    node.left  = bstPut(node.left, s);
  }
  else if (strcmp(s,node.str) > 0){
    node.right = bstPut(node.right, s);
  }
  else{//duplicate
    return node;
  }
 
  node.height = 1 + max(height(node->left),
			 height(node->right));
 
  int balance = getBalance(node);
  
  // Left Left Case
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);
 
  // Right Right Case
  if (balance < -1 && key > node->right->key)
    return leftRotate(node);
 
  // Left Right Case
  if (balance > 1 && key > node->left->key)
    {
      node->left =  leftRotate(node->left);
      return rightRotate(node);
    }
 
  // Right Left Case
  if (balance < -1 && key < node->right->key)
    {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
 
  /* return the (unchanged) node pointer */
  return node;

    


  /* i = new item containing s */
  i = (LLItem *)malloc(sizeof(LLItem));
  i->str = scopy;
  i->next = 0;

  /* append to end of list */
  if (lp->last) {			/* list not empty */
    lp->last->next = i;
  } else {			/* list empty */
    lp->first = i;
  }

  /* new item is last on list */
  lp->last = i;
  doCheck(lp);
}

/* print list membership.  Prints default mesage if message is NULL */
void llPrint(LList *lp, char *msg)
{
  LLItem *ip;
  int count = 1;
  doCheck(lp);
  puts(msg ? msg :" List contents:");
  for (ip = lp->first; ip; ip = ip->next) {
    printf("  %d: <%s>\n", count, ip->str);
    count++;
  }
}

// A utility function to get height of the tree
int height(struct bstNode *bstp)
{
    if (bstp == NULL)
        return 0;
    return N.height;
}
// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
int max(int a, int b){
  if(a >= b){
    return a;
  }
  else{
    return b;
  }
}
