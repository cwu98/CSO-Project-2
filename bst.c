#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

void add ( bst_node ** root, char * word ) {
  //create bst_node and allocate memory using malloc, has to be freed 
  bst_node *newNode=(bst_node*)malloc(sizeof(bst_node));
  newNode->data = word; //initiate newNode fields
  newNode->left = NULL;
  newNode->right = NULL;
  
  if(newNode == NULL){
    return;
  }

  bst_node *currNode = *root;
  
  if(!*root) { //tree is empty
    //set root to point to newNode
    (*root) = newNode;
    return;
  }
  bst_node *follow = NULL;
  int flag; //flag keeps track of whether newNode should be on left or right
  while (currNode) { //if currNode not null..
    //compare strings
    int compare = strcmp(word, currNode->data);
    follow = currNode;
 
    if (compare < 0) { //word is smaller than current node's data, go left
      currNode = currNode->left;
      flag = 1; //newNode is on the left of tree
    }
    else { //go right
      currNode = currNode->right;
      flag = 0; //newNode is on the right of tree
    }//endif
  }//endwhile
    if(flag){ //newNode belongs on left of node at *follow
      follow->left = newNode;
      
    }
    else{
      follow->right = newNode;
      
    }//endif
   
    }//end_add

 
void inorder ( bst_node * root ) {
  
  if(!root){ //root points to NULL  
    return;
  }
  inorder(root->left); //recurse left 
  if(root){
    printf("%s ", root->data); //print word
  }
  inorder(root->right); //recurse right
}


 
char * removeSmallest (  bst_node ** root ){
  bst_node *follower = NULL; //keep track of parent of the node we want to remove
  bst_node *ptr=*root;
  char *word;
  if(!*root){ //root points to NULL
    return NULL;
  }
  else if(ptr->left == NULL){//root is smallest
    word = ptr->data;
    (*root) = ptr->right; //set root to point to right subtree
    
    free(ptr); //remove what was the root
    ptr = NULL;
    return word;
  }
  while(ptr->left != NULL){//find the smallest node 
    follower = ptr;
    ptr = ptr->left;
  }//end while    
   word = ptr->data;
   follower->left = ptr->right;
   free(ptr); //remove node
   ptr = NULL;
   //ptr = NULL;
   return word;

}

 
char * removeLargest (  bst_node ** root ){
  bst_node *follower = NULL; //keep track of parent of the node we want to remove
    bst_node *ptr =*root;
    char *word;
    if(!*root){ //root points to NULL
      return NULL;
    }
    else if(ptr->right == NULL){//root is largest
      word = ptr->data;
      (*root) = ptr->left; //update new root
      free(ptr); //remove
      ptr = NULL;
      return word;
    }
    while(ptr->right){//loop to find the right most node
      follower = ptr;
      ptr = ptr->right; 
    }
    word= ptr->data;
    follower->right = ptr->left;
    free(ptr); //remove
    ptr = NULL;

  
    return word;
}




