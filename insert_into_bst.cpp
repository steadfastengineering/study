// You are given the root node of a binary search tree (BST) and a value 
// to insert into the tree. Return the root node of the BST after the 
// insertion. It is guaranteed that the new value does not exist in the 
// original BST.

// Notice that there may exist multiple valid ways for the insertion, as 
// long as the tree remains a BST after insertion. You can return any of 
// them.

#include <iostream>
#include <string>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) 
{
    if(root == nullptr && val == 0) return root;

    if(root == nullptr)
    {
        root = new TreeNode();
    }

    TreeNode* temp = root;
    while(true)
    {
        if(temp->val == 0)
        {
            temp->val = val;
            break;
        }
        else if(val > temp->val)
        {
            // process right node
            if(temp->right == nullptr)
            {
                temp->right = new TreeNode();
            }
            temp = temp->right;
        }
        else if(val < temp->val)
        {
            // process left node
            if(temp->left == nullptr)
            {
                temp->left = new TreeNode();
            }
            temp = temp->left;
        }
    }
    return root; 
}

int main()
{
    //TODO 
    return 0;
}