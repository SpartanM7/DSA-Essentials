// this code is for the inorder traversal of BST
#include<iostream>
using namespace std;

class Treenode{
    public: 
    int val;
    Treenode *left;
    Treenode *right;

    public:
    //constructor for the tree
    Treenode(int x) : val(x) , left(nullptr) , right(nullptr) {}
};

class postorderTraversal
{
    public:
    void postorder(Treenode *root){
       // base case 
        if(root == nullptr) return;

        postorder(root->left);
        postorder(root->right);
        cout << root->val; 
}

int main()
{
        
    return 0;
}