#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

/*
There is an undirected tree with n nodes labeled from 0 to n - 1, and rooted at
node 0.

You are given a 2D integer array edges of length n - 1, where edges[i] = [ai,
bi] indicates that there is an edge between nodes ai and bi in the tree.

A node is good if all the subtrees rooted at its children have the s size.

Return the number of good nodes in the given tree.
A subtree of treeName is a tree consisting of a node in treeName and all of its
descendants.
*/

class DirectedSolution {
public:
  // NOTE THIS SOLUTION IS WRONG BECAUSE IT ASSUMED A DIRECTED GRAPH,
  // IN WHICH EACH edge has direction eg: [parent, child].

  // a node is good if it has the s total number of nodes below each child.
  // --> a node is good if it's children have the s number edges
  // the key is to realize the following:
  // total nodes = edges.size()+1  // there is one more node than edges in a
  // tree the format of the edges is [<parent nodel label>, <child node label>]
  vector<int> get_immediate_children(vector<vector<int>> &edges, int node) {
    // gets all immediate children
    vector<int> children;
    for (auto edge : edges) {
      if (edge[0] == node) {
        children.push_back(edge[1]);
      }
    }
    return children;
  }

  void get_all_children(vector<vector<int>> &edges, int node,
                        vector<int> &children) {

    // gets all immediate children
    vector<int> new_children;
    for (auto edge : edges) {
      if (edge[0] == node) {
        // if the current edge has the node number in the parent position,
        // save the node value of the child position.
        new_children.push_back(edge[1]);
      }
    }

    for (auto child : new_children) {
      children.push_back(child);
    }

    for (auto immediate_child : new_children) {
      get_all_children(edges, immediate_child, children);
    }
  }

  int countGoodNodes(vector<vector<int>> &edges) {

    int total_nodes = edges.size() + 1; // there is one more node than edges.
    vector<int> good_nodes;
    for (int node = 0; node < total_nodes; node++) {
      vector<int> immediate_children = get_immediate_children(edges, node);
      vector<int> grandchildren_counts;
      for (int child : immediate_children) {
        // for all immediate children, count their grand children
        vector<int> all_children = {};
        get_all_children(edges, child, all_children);
        grandchildren_counts.push_back(all_children.size());
      }

      bool is_good = true; // if it had children, we compare the counts,
                           // otherwise it was a leaf node and it's good!
      for (auto grandchildren : grandchildren_counts) {
        // if any of the grand children counts don't match, then the node is not
        // good
        int first = grandchildren_counts[0];
        if (grandchildren != first) {
          is_good = false;
          break;
        }
      }

      if (is_good)
        good_nodes.push_back(node);
    }

    return good_nodes.size();
  }
};

class Solution {
public:
  template <typename T> void print(vector<T> v) {
    for (T e : v) {
      cout << e << " ";
    }
    cout << endl;
  }

  // traverse the tree DFS, counting all the nodes below the given node.
  int count_descendants(vector<vector<int>> &adjacency_list, int node, int prev) {

    vector<bool> visited = vector(adjacency_list.size(), false);
    stack<int> nodes; 
    nodes.push(node);

    int count = -1; // ignore the start node. 

    while (!nodes.empty()) {

      int current = nodes.top();
      nodes.pop(); 


      if(current != prev)
      {
        visited[current] = true; 
        for(int child : adjacency_list[current])
        {
          if(!visited[child])
          {  
            // push any adjacent onto the stack, that wasn't a previous node
            nodes.push(child);
          }
        }
        count++; 
      }  
       

    }
 
    return count;
  }

  int get_subtree_size(vector<vector<int>> &adjacency_list, vector<bool> &visited, int root, int prev = -1)
  {
    int count = 1; 
    visited[root] true;
    for(auto neighbor : adjacency_list[root])
    { 
      if(neighbor != prev && !visited[neighbor])
      { 
        prev = root;
        int children_count = get_subtree_size(adjacency_list, visited, neighbor, prev);
        count += children_count;
      }
    }
    return count;
  }



  vector<vector<int>> get_adjacency_list(vector<vector<int>> &edges) {
    int total_nodes = edges.size() + 1;
    vector<vector<int>> adjacency_list(total_nodes, vector<int>());
    for (int node = 0; node < adjacency_list.size(); node++) {
      vector<int> neighbors = {};
      for (auto edge : edges) {
        if (edge[0] == node) {
          neighbors.push_back(edge[1]);
        } else if (edge[1] == node) {
          neighbors.push_back(edge[0]);
        }
      }
      adjacency_list[node] = neighbors; 
    }
    return adjacency_list;
  }

  int countGoodNodes(vector<vector<int>> &edges) {
     
    // this is a tree, which means that we have 1 more node, than edges (no
    // cycles!)
    const int total_nodes = edges.size() + 1;
    vector<vector<int>> adjacency_list = get_adjacency_list(edges);
      
    // track the nodes we've been to before.
    vector<bool> previous = vector(total_nodes, false);

    cout << "0 subtree size: " << get_subtree_size(adjacency_list, previous, 0) << endl;
    cout << "1 subtree size: " << get_subtree_size(adjacency_list, previous, 0) << endl;
    cout << "2 subtree size: " << get_subtree_size(adjacency_list, previous, 0) << endl;

    // for any given node store a list of the counts of nodes of each child.
    vector<vector<int>> subtree_counts = vector(total_nodes, vector<int>());
    
    for (int node = 0; node < total_nodes; node++) {
       
      vector<int> children = adjacency_list[node];
      vector<int> counts;
      //previous[node] = true;
      int prev = -1;
      for (auto child : children) { 
        int count = count_descendants(adjacency_list, child, prev); 
        counts.push_back(count); 
        prev = child;
      }
      subtree_counts[node] = counts;
    }

    for(int i = 0; i < total_nodes; i++)
    {
      cout << "node:" << i << " sub_tree_counts:";
      print(subtree_counts[i]);
    }

 
    // if any node's children have the same counts, or no counts (leaf node), it
    // is a good node
    vector<int> good_nodes;
    for (int node = 0; node < total_nodes; node++) {
      vector<int> counts = subtree_counts[node];
      bool is_good = true;
      if (counts.size() > 0) {
        int first = counts[0];
        for (auto count : counts) {
          if (count != first) {
            is_good = false;
            break;
          }
        }
        good_nodes.push_back(node);
      }
    }
    return good_nodes.size();
   
  }
};

int main() {
  vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 3},
                                {1, 4}, {2, 5}, {2, 6}}; // Answer: 7
  vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 3}, {3, 4},
                                {0, 5}, {1, 6}, {2, 7}, {3, 8}}; // Answer: 6
  vector<vector<int>> edges3 = {{6, 0}, {1, 0}, {5, 1},
                                {2, 5}, {3, 1}, {4, 3}}; // Answer: 6

  Solution *s = new Solution();
  // cout << "total: " << s->countGoodNodes(edges1) << endl;
  cout << s->countGoodNodes(edges3);
  //cout << "total: " << s->countGoodNodes(edges3);
  return 0;
}