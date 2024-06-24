It is an hirechal data structure.
Evey node has data and 2 pointers for the right and left children nodesi.
Creating a tree is similar to creating a linked list, but the strucutre differs in trees.
The topmost part of the tree is called the root and the  bottom most part is called the leafs.
A tree can be classified between balanced and unbalanced.

- Traversal of tree
There are 2 different ways of traversal of trees
    - DFS (depth first search) Trick : see the position of the root in respect to the name
    1. Inorder Traversal: This method follows the order [left root right].
    2.Pre-order traversal : This method follows the order [root left right].
    3. Post-order traversal : This method follow the order [left right root].
    - BFS (Breadth First Search): This method visits all the nodes at the present level before moving on to nodes one layer below.

- Psuedo Code for DFS Pre-order traversal : TC:O(N) //in case of skew tree SC:O(N)//since all the nodes need to be tranversed
    void preOrderTraversal(node* root)
    {
        if(root == null) return // base case
        print(root->data) // printing the data
        preOrderTraversal(root->left) // going to the left of subtree
        preOrderTraversal(root->right) // going to the right of subtree
    }

    void inOrderTraversal(node *root)
    {
        if(node == null) return 
        inOrderTraversal(root->left)
        print(root->data)
        inOrderTraversal(root->right)
    }