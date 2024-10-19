// You are given the root of a binary search tree (BST) and an integer val.

// Find the node in the BST that the node's value equals val and return the 
// subtree rooted with that node. If such a node does not exist, return null.


  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

TreeNode* searchBST(TreeNode* root, int val) 
{
    if(root == nullptr) return root; 

    TreeNode* temp = root;
    while(true)
    {   
        if(temp == nullptr) return temp;
        if(temp->val == val) return temp;

        if(val > temp->val)
        {
            temp = temp->right;
        } 
        else{
            temp = temp->left;
        }
    }
}