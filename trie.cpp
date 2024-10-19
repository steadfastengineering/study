#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{
  public:
    Node* children[26];
    char letter;
    bool isWord;
};

int getIndexOfChar(char c)
{
  return (c - 'a');
}

void insertWord(Node* root, char* word)
{
  Node* current = root;
  for(int i = 0; i < word[i] != '\0'; i++)
  {
    int position = getIndexOfChar(word[i]);
    if(current->children[position] == NULL)
    {
      Node* child = new Node();

      child->letter = word[i];
      current->children[position] = child;
      current = child;
    }
    else
    {
      current = current->children[position];
    }
  }
  current->isWord = true;
}

void searchWord(Node* root, char* s)
{
  // todo
}

void printTrie(Node* root)
{
  if(root == NULL)
  {
    return;
  }

  cout << root->letter;
  if(root->isWord){
    cout << endl;
  }

  for(int i = 0; i<26; i++)
  {
    printTrie(root->children[i]);
  }

}

int main()
{
  Node* root = new Node();
  char s1[] = "racket";
  char s2[] = "deep";
  char s3[] = "nimble";
  char s4[] = "nibble";
  insertWord(root, s1);
  insertWord(root, s2);
  insertWord(root, s3);
  insertWord(root, s4);

  printTrie(root);
}
