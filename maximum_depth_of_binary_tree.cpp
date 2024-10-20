#include<iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:

    // get the height of the subtree  counting the root.
  int get_height(TreeNode *root, int level = 0) {
    if (root == nullptr)
      return level;  

    level++;
    if (root->left != nullptr && root->right != nullptr) {
      int left_height = get_height(root->left, level);
      int right_height = get_height(root->right, level);
      return left_height > right_height ? left_height : right_height;
    } else if (root->left == nullptr) {
      return get_height(root->right, level);
    } else {
      return get_height(root->left, level);
    }
  }

    int maxDepth(TreeNode* root) {
        return get_height(root);
    }
};


int main()
{
    return 0;
}