#include <iostream>
using namespace std;
#include <queue>

struct Treenode
{
    int val;
    Treenode *left;
    Treenode *right;
    Treenode(int x) : val(x) , left(nullptr) , right(nullptr) {}
};

class solution
{
    public:
    vector<vector<int>> levelOrder(Treenode *root)
    {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<Treenode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++)
            {
                Treenode *node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

int main()
{

    return 0;
}