#include <iostream>
#include <vector>

using namespace std;

/*
There is an undirected tree with n nodes labeled from 0 to n - 1, and rooted at
node 0.

You are given a 2D integer array edges of length n - 1, where edges[i] = [ai,
bi] indicates that there is an edge between nodes ai and bi in the tree.

A node is good if all the subtrees rooted at its children have the same size.

Return the number of good nodes in the given tree.
A subtree of treeName is a tree consisting of a node in treeName and all of its
descendants.
*/

class Solution {
public:
  // a node is good if it has the same total number of nodes below each child.
  // a node is good if it's children have the same number edges

  int count_leaf_nodes(vector<vector<int>> &edges, int node) {
    // count child nodes --> all leaf nodes are good nodes
    // [parent, child]
    vector<int> leaf_nodes;
    for (int i = edges.size() - 1; i > 0; i--) {
      int node = edges[i][1];
      bool is_parent = false;
      for (int k = edges.size() - 1; k > 0; k--) {
        if (edges[k][0] == node) {
          // we found our node as a parent, no need to proceed, record it
          is_parent = true;
          break;
        }
      }
      if (!is_parent)
        leaf_nodes.push_back(node);
    } 
    return leaf_nodes.size();
  }

  vector<int> get_immediate_children(vector<vector<int>> &edges, int node)
  {
    int parent = 0;
    int child = 1; 
    // gets all immediate children
      vector<int> children;
      for (auto edge : edges) {
        if (edge[parent] == node) {
          children.push_back(edge[child]);
        }
      } 
      return children;
  }

  void get_all_children(vector<vector<int>> &edges, int node, vector<int> &children) {
   
      // gets all immediate children
      vector<int> new_children;
      for (auto edge : edges) {
        if (edge[0] == node) {
          // if the current edge has the node number in the parent position, 
          // save the node value of the child position.
          new_children.push_back(edge[1]);
        }
      } 

      for(auto child : new_children)
      {
        children.push_back(child);
      }

      cout << "found children: " << children.size() << " under node: " << node << endl;

      for(auto immediate_child : new_children)
      {
        get_all_children(edges, immediate_child, children);
      }
  }

  int countGoodNodes(vector<vector<int>> &edges) {


    int total_nodes = edges.size() + 1; // there is one more node than edges.
    vector<int> good_nodes;
    for(int node = 0; node < total_nodes; node++)
    {
        vector<int> immediate_children = get_immediate_children(edges, node);
        vector<int> grandchildren_counts;
        for(int child : immediate_children)
        {
            vector<int> all_children = {};
            get_all_children(edges, node, all_children);
            grandchildren_counts.push_back(all_children.size());
        }

        cout << "good nodes: ";
        for(auto gd : good_nodes)
        {
          cout << gd << ",";
        }
        cout << endl;

        bool is_good = true;
        int first = grandchildren_counts[0];
        for(auto grand_child : grandchildren_counts)
        {
            if(grand_child != first) {
                is_good = false;
                break;
            }
        }

        if(is_good) good_nodes.push_back(node);
    }

    return good_nodes.size();
  }
};

int main() {
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};

  Solution *s = new Solution();
  cout << s->countGoodNodes(edges);
  return 0;
}