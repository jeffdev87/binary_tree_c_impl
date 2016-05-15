#include "binary.h"

treeType * init () {
   treeType * tt = (treeType*) malloc(sizeof(treeType));
   if (tt == NULL)
      return NULL;

   tt->root = NULL;
   tt->nElem = 0;

   return tt;
}

// Pointer to pointer applies here because I want to make changes in the
// value of a pointer (left or right) without loosing these changes after the function dies.
static int addBinaryTreeElem(elemType ** et, elemType * e) {

   if (*et == NULL) {
      *et = e;
      return 1;
   }  

   if (e->value < (*et)->value)
                                //address of the content of a variable that is a pointer too
      return (addBinaryTreeElem(&(*et)->l, e));
   else
      return (addBinaryTreeElem(&(*et)->r, e));
}

int add (treeType * t, int value) {
   if (t == NULL)
      return -1;

   elemType * e = (elemType*) malloc(sizeof(elemType));
   if (e == NULL)
      return -1;

   e->value = value;
   e->r = NULL;
   e->l = NULL;

   if (t->nElem == 0 && t->root == NULL) {
      t->root = e;
      t->nElem++;
   }
   else {
      if (addBinaryTreeElem(&(t->root), e) == 1) 
         t->nElem++;
   }  
      
   return 1;
}

void printRootValue (treeType * tt) {
   if (tt != NULL && tt->root != NULL)
      printf("Root value: %d\n", tt->root->value);
   else
      printf("Null tree!!!\n");
}

void traversal (treeType * tt, int type){
   if (tt == NULL) {
      printf("Empty tree!\n");
      return;
   }
   
   switch (type) {
      case 0:
         printf("Inorder traversal\n");
         inOrder(tt->root);
      break;
      case 1:
         printf("Preorder traversal\n");
         preOrder(tt->root);
      break;
      case 2:
         printf("Posorder traversal\n");
         posOrder(tt->root);
      break;
      
      default:
      break;
   }
   printf("\n");
}

static void inOrder (elemType * e) {
   if (e == NULL)
      return;
   
   inOrder(e->l);
   printf("%d ", e->value);
   inOrder(e->r);
}

static void preOrder (elemType * e) {
   if (e == NULL)
      return;

   printf("%d ", e->value);
   preOrder(e->l);
   preOrder(e->r);
}

static void posOrder (elemType * e) {
   if (e == NULL)
      return;

   posOrder(e->l);
   posOrder(e->r);
   printf("%d ", e->value);
}

int findMinimal (elemType * r) {
   if (r->l == NULL)
      return r->value;

   return (findMinimal(r->l)); 
}

int findMax (elemType * r) {
   if (r->r == NULL)
      return r->value;

   return (findMax(r->r));
}

int search (elemType * root, int val) {
   if (root == NULL)
      return -1;

   if (root->value == val)
      return val;
   else if (val < root->value)
      return (search(root->l, val));
   else
      return (search(root->r, val));
}

