
#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include "AVLbst.h"		


/* create a new tree */
bst *bstAlloc()
{
  bst *bstp = (struct bst *) malloc(sizeof(bst));
  bstp->root = 0;
  return bstp;
}

/* recycle a tree */
void bstFree(struct bst *bstp)
{
  free(bstp);
}
  
/* append a copy of str to bst and balance must be handed a node not full tree for recursion to work */
struct bstNode *bstPut(struct bstNode *node, char *s){
  
  /*normal insertion */
  if(node== NULL){
    int len;
    char *scopy;

    for (len = 0; s[len]; len++) /* compute length */
      ;
    scopy = (char *)malloc(len+1);
    for (len = 0; s[len]; len++){ /* copy chars */
      scopy[len] = s[len];
    }
    scopy[len] = 0;			/* terminate copy */

    struct bstNode *newNode = (struct bstNode *)malloc(sizeof(bstNode));
    bstNode->str
    return(newNode);
  }
  if (strcmp(s, node->str) < 0){
    node->left  = bstPut(node->left, s);
  }
  else if (strcmp(s,node->str) > 0){
    node->right = bstPut(node->right, s);
  }
  else{//duplicate
    return node;
  }

  //On the way back
  node->height = 1 + max(height(node->left),height(node->right));
 
  int balance = getBalance(node);
  
  // Left Left Case
  if (balance > 1 && strcmp(key, node->left->str) < 0){
    return rightRotate(node);
  }
  // Right Right Case
  if (balance < -1 && strcmp(key, node->right->str) > 0){
    return leftRotate(node);
  }
  // Left Right Case
  if (balance > 1 && strcmp(key, node->left->key) > 0){
    node->left =  leftRotate(node->left);
    return rightRotate(node);
  }
 
  // Right Left Case
  if (balance < -1 && strcmp(key, node->right->key) < 0){
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }
 
  return node;
}

void bstPrint(struct bst *bstp, char *msg){
  msg ? msg : " Employee tree contents:";
  printf("%s \n", msg);
  nodePrint(bstp->root);
}

void nodePrint(struct bstNode *bp){
  if(bp == NULL){
    return;
  }
  nodePrint(bp->left);
  printf("  %d: <%s>\n", bp->hieght, bp->str);
  nodePrint(bp->right);
  return;
}

int height(struct bstNode *bstp)
{
    if (bstp == NULL)
        return 0;
    return N->height;
}


struct bstNode *rightRotate(struct bstNode *y)
{
    struct bstNode *x = y->left;
    struct bstNode *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    return x;
}
 
struct bstNode *leftRotate(struct bstNode *x)
{
    struct bstNode *y = x->right;
    struct bstNode *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    return y;
}
 
int getBalance(struct bstNode *N)
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

