#ifndef BINARY_H
#define BINARY_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct elemTypeStr {
   int value;
   struct elemTypeStr * r;
   struct elemTypeStr * l;
} elemType;

typedef struct treeTypeStr {
   elemType * root;
   int nElem;
} treeType;

treeType * init ();

static int addBinaryTreeElem(elemType ** et, elemType * e);

int add (treeType * t, int value);

void printRootValue (treeType * tt);

void traversal (treeType * tt, int type);

static void inOrder (elemType * e);
static void posOrder (elemType * e);
static void preOrder (elemType * e);

int findMinimal (elemType * r);
int findMax (elemType * r);

int search (elemType * root, int val);

#endif /* BINARY_H */
