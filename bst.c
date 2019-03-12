#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

void add ( bst_node ** root, char * word ) {
  bst_node *newNode=(bst_node*)malloc(sizeof(bst_node));
  newNode->data = word;
  newNode->left = NULL;
  newNode->right = NULL;
  //printf("new node created: %s\n", newNode->data);
  if(newNode == NULL){
    return;
  }
  bst_node *currNode = *root;
  
  if(!*root) { //tree is empty
    //printf("root word: %s \n", newNode->data);
    (*root) = newNode;
    return;
  }
  bst_node *follow = NULL;
  int flag;
  while (currNode) { //if currNode not null..
    int compare = strcmp(word, currNode->data);
    follow = currNode;
    // printf("strcmp value is: %d\n", compare);
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
      //printf("ended up on left \n");
    }
    else{
      follow->right = newNode;
      // printf("ended up on right \n");
    }//endif
   
    }//end_add

 
void inorder ( bst_node * root ) {
  
  if(!root){  
    return;
  }
  inorder(root->left);
  if(root){
    printf("%s ", root->data);
  }
  inorder(root->right);
}


 
char * removeSmallest (  bst_node ** root ){
  bst_node *follower = NULL;
  bst_node *ptr=*root;
  char *word;
  if(!*root){
    return NULL;
  }
  else if(ptr->left == NULL){//root is smallest
    word = ptr->data;
    (*root) = ptr->right;
    
    free(ptr);
    ptr = NULL;
    return word;
  }
 while(ptr->left != NULL){
    follower = ptr;
    ptr = ptr->left;
   }    
   word = ptr->data;
   follower->left = ptr->right;
   free(ptr);
   ptr = NULL;
   //ptr = NULL;
   return word;

}

 
char * removeLargest (  bst_node ** root ){
    bst_node *follower = NULL;
    bst_node *ptr =*root;
    char *word;
    if(!*root){
      return NULL;
    }
    else if(ptr->right == NULL){//root is largest
      word = ptr->data;
      (*root) = ptr->left; //update new root
      free(ptr);
      ptr = NULL;
      return word;
    }
    while(ptr->right){
      follower = ptr;
      ptr = ptr->right; 
    }
    word= ptr->data;
    follower->right = ptr->left;
    free(ptr);
    ptr = NULL;

  
    return word;
}




