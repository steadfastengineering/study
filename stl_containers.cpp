#include <iostream>
#include <map>
#include <set> 
#include <string>
#include <vector>

using namespace std;

int main() {

  // maps  (unordered)
  map<int, string> my_map;
  my_map.insert({1, "derp"});
  my_map.insert({3, "herp derp"});
  for (auto iter : my_map) {
    cout << iter.first << " " << iter.second << endl;
  }
  my_map.insert(
      {3, "slow is smooth and smooth is fast"}); // fails, can't insert
                                                 // duplicate keys!
  for (auto iter : my_map) {
    cout << iter.first << " " << iter.second << endl;
  }
  my_map[3] =
      "slow is smooth and smooth is fast"; // works because we are updating!
  for (auto iter : my_map) {
    cout << iter.first << " " << iter.second << endl;
  }
  my_map.erase(1);                // erase the Key-Value pair by key 1.
  cout << my_map[1] << endl;      // prints nothing after the erase.
  cout << my_map.empty() << endl; // prints 0 because it is false.




  // sets
  set<int> my_set = {6, 10, 5, 900,
                     1}; // Will be stored in-order! No duplicates.
  cout << "My set: "; // Cannot modify elements in the set, only add or remove.
  for (auto iter : my_set) {
    cout << iter << " "; // Prints in order
  }
  cout << endl;
  my_set.erase(900); // erase value from set
  for (auto iter : my_set) {
    cout << iter << " "; // Prints in order
  }
  cout << endl;


  // vectors 
  vector<int> v = vector(10, -1); // initialize a vector of 10 elements with -1
  cout << "my vector: ";
  for(auto iter : v) cout << iter;

  cout << endl;
  v.push_back(200); // add to rear of vector
  v[1] = 99; // assign value to specific index
  cout << v.empty() << endl; // prints 0 because v has items
 for(auto iter : v) cout << iter;

  return 0;
}