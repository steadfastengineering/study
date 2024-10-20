#include <cmath>
#include <iostream>
#include <string>
#include <vector>

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

/*
    A balanced binary tree is a tree in which the height of any two subtrees
    never differs by more than one.
*/

class Solution {
public:
  bool balanced = true;

  // get the height of the subtree  counting the root.
  int get_height(TreeNode *root, int level = 0) {
    if (root == nullptr)
      return level; //level == -1 ? 0 : level;

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

  void check_every_node(TreeNode *root) {
    if (root == nullptr)
      return;

    check_every_node(root->left);
    int left = get_height(root->left);
    int right = get_height(root->right);
    if (abs(left - right) > 1) {
      balanced = false;
      return;
    }
    check_every_node(root->right);
    left = get_height(root->left);
    right = get_height(root->right);
    if (abs(left - right) > 1) {
      balanced = false;
      return;
    }
  }

  bool isBalanced(TreeNode *root) {
    check_every_node(root);
    return balanced;
  }
};

// This builds a BST, not just a BT. Using only for convience to
// build trees and check them for balance.
void insert(TreeNode *root, int data) {
  if (root == nullptr) {
    return;
  }

  if (root->val == 0) {
    root->val = data;
  } else if (root->val > data) {
    if (root->left == nullptr) {
      root->left = new TreeNode();
    }
    insert(root->left, data);
  } else { // root->data <= data
    if (root->right == nullptr) {
      root->right = new TreeNode();
    }
    insert(root->right, data);
  }
}

int main() {
  vector<int> v = {7, 5, 4, 3, 2, 1};
  TreeNode *root = new TreeNode();
  for (auto e : v) {
    insert(root, e);
  }

  Solution *s = new Solution();
  cout << "is balanced: " << s->isBalanced(root) << endl;
  cout << s->get_height(root) << endl;
}