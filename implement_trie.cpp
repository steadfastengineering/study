
// A trie (pronounced as "try") or prefix tree is a tree data structure 
// used to efficiently store and retrieve keys in a dataset of strings. 
// There are various applications of this data structure, such as 
// autocomplete and spellchecker.

// Implement the Trie class:

// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the 
// trie (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously
// inserted string word that has the prefix prefix, and false otherwise.

// This solution works fine on my intel machine but the Leet Code sanitizer
// complains about it. 

#include <iostream>
#include <string>

using namespace std;


class Node
{
    public:
    char letter = '\0';
    Node* children[26] = {}; // restricted to a-z lower. lookup table yo!
    bool is_word = false; 
};

class Trie
{ 
    private: 
    Node* root;

    public: 
        Trie() 
        {
            
        }
        
        void insert(string word) 
        {
            if(word == "") return;
            if(root == nullptr)
            {
                //cout << "instantiating root node" << endl;
                root = new Node(); // root starts as !nullptr
            }

            Node* current = root;
            for(int i = 0; i < word.length(); i++)
            {
                int position = tolower(word[i]) - 'a';
                
                // create child if it doesn't exist
                if(current->children[position] == nullptr)
                {
                    // debug
                    //cout << "child not exist, inserting at: " << position << endl;
                    Node* child = new Node();
                    child->letter = tolower(word[i]);
                    //if(i == word.length() - 1) child->is_word = true;
                    current->children[position] = child;
                }                
                
                // move to that child node!
                current = current->children[position];
            }
            current->is_word = true;
        }
        
        bool search(string word) 
        {
            if(word == "")return false;
            if(root == nullptr) return false;
            bool in_tree = false;
            Node* current = root;
            for(int i=0; i < word.length(); i++)
            {
                int position = word[i] - 'a';
                if(current->children[position] == nullptr) return false;
                if(current->children[position]->is_word){
                    in_tree = true;
                    break;
                }
                current = current->children[position];
            }

            return in_tree;
        }
        
        bool startsWith(string prefix) {
            if(prefix == "")return false; 
            if(root == nullptr) return false;
            Node* current = root;

            for(int i=0; i < prefix.length(); i++)
            {
                int position = prefix[i] - 'a';
                if(current->children[position] == nullptr) return false;
                 
                current = current->children[position];
            } 
            return true;
        }

        void print()
        {  
            print_rec(root, "");
        }

        // recursive print
        void print_rec(Node* root, string word_so_far)
        {
            if(root == nullptr) return;
             
            word_so_far += root->letter;

            if(root->is_word)
            {   
                cout << word_so_far << endl;
            }

            for(int i = 0; i < 26; i++)
            {
                print_rec(root->children[i], word_so_far);
            }
        }

};
    int main()
    {
        Trie* t = new Trie();
        t->insert("apple");
        cout << t->search("apple") << endl;
        cout << t->search("app") << endl;
        cout << t->startsWith("app") << endl;
        t->insert("app");
        cout << t->search("app") << endl;

        t->print();
        //cout << "act: " << t->search("act") << endl;
        //cout << "activate: " << t->search("activate") << endl;

        return 0;
    }