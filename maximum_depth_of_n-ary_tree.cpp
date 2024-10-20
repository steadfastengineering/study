#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
public:
  vector<int> heights;
  int get_height(Node *root, int height = 0) {
    if (root == nullptr)
      return height;

    height++;

    int max = 0;
    for (Node *node : root->children) {
      int sub_height = get_height(node, height);
      if (sub_height > max)
        max = sub_height;
    }
    return max == 0 ? height : max;
  }

  int maxDepth(Node *root) { return get_height(root); }
};

int main() {

  // Solution works online, to run here, build local here n-ary tree here for testing. 

  Node *root = new Node();
  Solution *s = new Solution();
  cout << s->maxDepth(root) << endl;

  return 0;
}