#include "binary.h"

int main() {
   
   treeType * t = init();
   if (t == NULL) {
      printf("Error!!!\n");
      return 0;
   }
   
   printf("Size: %d\n", t->nElem);
   printRootValue(t);

   add(t, 100);
   add(t, 20);
   add(t, 101);
   add(t, 50);
   add(t, 29);
   add(t, 1);
   add(t, 900);

   //printRootValue(t);
   printf("Size: %d\n", t->nElem);
   
   traversal(t, 0);
   traversal(t, 1);
   traversal(t, 2);

   printf("Min: %d\n", findMinimal(t->root));
   printf("Max: %d\n", findMax(t->root));

   int found = search(t->root, 50);
   printf("Search: %d\n", found); 
   
   found = search(t->root, 2);
   printf("Search: %d\n", found);

   return 0;
}
