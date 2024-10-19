/*
  Binary Search Tree Practice
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

class Node{
public:
  Node* left = NULL;
  Node* right = NULL;
  int data = -1;
};

void insert(Node* root, int data){
  if(root == NULL){
    return;
  }

  if(root->data == -1){
    root->data = data;
  } else if(root->data > data){
    if(root->left == NULL){
      root->left = new Node();
    }
    insert(root->left, data);
  } else{ // root->data <= data
    if(root->right == NULL){
      root->right = new Node();
    }
    insert(root->right, data);
  }
}

void printPreOrder(Node* root){
  if(root == NULL){
    return;
  }

  cout << root->data << " ";
  printPreOrder(root->left);
  printPreOrder(root->right);
}

void printInOrder(Node* root){
  if(root == NULL){
    return;
  }

  printInOrder(root->left);
  cout << root->data << " ";
  printInOrder(root->right);
}

void printPostOrder(Node* root){
  if(root == NULL){
    return;
  }

  printPostOrder(root->left);
  printPostOrder(root->right);
  cout << root->data << " ";
}

int main(){

  // Create root
  Node* tree = new Node();

  // Populate
  srand(time(NULL));
  int data;
  cout << "Data: ";
  for(int i = 0; i < 20; i++){
    data = rand() % 100 + 1; // random number between [1, 100]
    cout << data << " ";
    insert(tree, data);
  }

  // Print Tree
  cout << endl << "In order: " << endl;
  printInOrder(tree);

  cout << endl << "Pre ordered: " << endl;
  printPreOrder(tree);

  cout << endl << "Post ordered:" << endl;
  printPostOrder(tree);
  return 0;
}
