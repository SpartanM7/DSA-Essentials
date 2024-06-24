// This code includes 2 approaches to convert a given array to preorder BST 1. Brute Force 2. Optimal Solution

#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

// Definition of TreeNode structure
// for a binary tree node
struct TreeNode {
    // Value of the node
    int val;
    
    // Pointer to the left child node
    TreeNode* left;
    
    // Pointer to the right child node
    TreeNode* right;

    // Constructor to initialize the node with a
    // value and set left and right pointers to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to construct a Binary Search Tree (BST)
    // from a given preorder traversal array
    // Brute force approach
    TreeNode* bstBruteForceFromPreorder(vector<int>& A) {
         // Return null if the array is empty
        if (A.empty()) {
            return NULL;
        }
        
        // First element as root
        TreeNode* root = new TreeNode(A[0]); 
    
        for (int i = 1; i < A.size(); ++i) {
            // Start from the root for each value
            TreeNode* curr = root; 
    
            // Traverse the tree to find
            // the appropriate position
            while (true) {
                if (A[i] < curr->val) {
                    if (curr->left == nullptr) {
                        // Insert as left child
                        curr->left = new TreeNode(A[i]); 
                        break;
                    } else {
                        // Move to left subtree
                        curr = curr->left; 
                    }
                    
                } else {
                    if (curr->right == nullptr) {
                        // Insert as right child
                        curr->right = new TreeNode(A[i]); 
                        break;
                    } else {
                        //  // Move to right subtree
                        curr = curr->right;
                    }
                }
            }
        }
         // Return the root of the constructed BST
        return root;
    }
    
   // optimal approach 
    TreeNode* bstOptimalFromPreorder(vector<int>& A)
    {
        // Initialize index for
        // traversal of the given array
        int i = 0; 
        
        // Call the build function starting
        // with the root node
        return build(A, i, INT_MAX); 
    }
    
    // Recursive function to construct the BST
    // from the preorder traversal array
    TreeNode* build(vector<int>& A, int& i, int bound) {
        // Check for conditions to return nullptr
        // indicating an invalid node or end of array
        if (i == A.size() || A[i] > bound) {
            return nullptr;
        }
        
        // Create a new node with the value at the
        // current index i of the preorder array
        TreeNode* root = new TreeNode(A[i++]);
    
        // Recursively build the left subtree using
        // values less than the current root's value
        root->left = build(A, i, root->val);
        
        // Recursively build the right subtree using
        // values within the bound specified
        root->right = build(A, i, bound);
        
        // Return the constructed node
        return root; 
    }
};

// Function to perform an in-order traversal
// of a binary tree and print its nodes
void printInOrder(TreeNode* root) {
    // Check if the current node
    // is null (base case for recursion)
    if (root == nullptr) {
        // If null, return and
        // terminate the function
        return;
    }

    // Recursively call printInOrder
    // for the left subtree
    printInOrder(root->left);

    // Print the value of the current node
    cout << root->val << " ";

    // Recursively call printInOrder
    // for the right subtree
    printInOrder(root->right);
}

int main() {
    Solution solution;
    
    // Example preorder traversal array
    vector<int> preorder = {8, 5, 1, 7, 10, 12}; 

    TreeNode* root = solution.bstBruteForceFromPreorder(preorder);

    cout << "Inorder Traversal of BST constructed from preorder traversal:" << endl;
    printInOrder(root);
    cout << endl;

    return 0;
}