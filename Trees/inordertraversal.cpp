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

class inorderTraversal
{
    public:
    void inorder(Treenode *root){
       // base case 
        if(root == nullptr) return;

        inorder(root->left);
        print(root->val);
        inorder(root->right);
    }
}

int main()
{
        
    return 0;
}