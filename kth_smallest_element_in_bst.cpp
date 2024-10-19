#include<iostream>
#include<vector> 

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

class Solution 
{
public: 
    
    int smallest = 0;
    int i = 0;

    void traverse_to_kth(TreeNode* root, int k)
    {
        if(root == nullptr) return;
        
        traverse_to_kth(root->left, k); 
        if(i == k) 
        { 
            smallest = root->val;
        } 
        i++;
        
        traverse_to_kth(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) 
    { 
        i = 0; // reset
        smallest = 0;   
        traverse_to_kth(root, k);   
        return smallest;
    }
};

void insert(TreeNode* root, int val)
{
    if(root == nullptr) return;
    
    if(root->val == 0)
    {
        root->val = val;
    }
    else if(val >= root->val) // greater than val, go right
    {
        if(root->right == nullptr)
        {
            root->right = new TreeNode(val); 
        }
        else
        {
            insert(root->right, val);
        }
    }
    else // less than val, go left
    {
        if(root->left == nullptr)
        {
            root->left = new TreeNode(val); 
        }
        else
        {
            insert(root->left, val);
        }
    }
}

int k = 0;
void print_in_order(TreeNode* root)
{
    if(root == nullptr) return;

    print_in_order(root->left);
    cout << "k:" << k << " " << root->val << endl;
    k++;
    print_in_order(root->right);
}

int kth = 0;
void print_kth(TreeNode* root, int i)
{
    if(root == nullptr) return;

    print_kth(root->left, i);
    if(kth == i) cout << "kth:" << kth << " " << root->val << endl;
    kth++;
    print_kth(root->right, i);
}


int main()
{
    TreeNode* root = new TreeNode();
    vector<int> v = {3,1,4,2};
    for(int e : v)
    {
        insert(root, e);
    }

    print_in_order(root);
    //print_kth(root, 8);


    // Problem solution:
    Solution s = Solution();
    cout << s.kthSmallest(root, 1) << endl;
    return 0;
}