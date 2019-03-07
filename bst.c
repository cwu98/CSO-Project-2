#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


void add ( bst_node ** root, char * word ) {
  bst_node newNode;
  bst_node *currNode = *root;
  while (currNode != NULL) {
    int compare = strcmp(*word, currNode->data);
    if (compare < 0) { //word is smaller than current node's data, go left
      currNode = &currNode->left;
    }
    else { //go right
      currNode = &currNode->right;
    }
  }
  *currNode = newNode;
  newNode.data = *word;
}

 
void inorder ( bst_node * root ) {
  if(root == NULL){
    printf("\n");
    return;
  }
  inorder(&root->left);
  printf("&s \n", *root->data);
  inorder(&root->right);
}


 
char * removeSmallest (  bst_node ** root ){
    
    return NULL;
}

 
char * removeLargest (  bst_node ** root ){
    
    return NULL;
}




