/*
Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether the two nodes are cousins of each other or not. Two nodes are said to be cousins of each other
if they are at same level of the Binary Tree and have different parents.
Do it in O(n).

Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Line 2 : integer value of p 
Line 3 : Integer value of q

Output format :
true or false

Constraints :
1 <= N <= 10^5

Sample Input :
5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1
2
4
Sample Output :
true
*/ 

// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/
bool isSibling(BinaryTreeNode<int> *root, int p, int q)
{
    if (root == NULL)
        return false;
    if (root->left != NULL && root->right != NULL)
        return ((root->left->data == p && root->right->data == q) || (root->left->data == q && root->right->data == p) 
                || isSibling(root->left, p, q) || isSibling(root->right, p, q));
    else
        return false;
}

int level(BinaryTreeNode<int> *root, int val, int lev)
{
    if (root == NULL)
        return 0;
    if (root->data == val)
        return lev;
    int l = level(root->left, val, lev + 1);
    if (l != 0)
        return l;
    return level(root->right, val, lev + 1);
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    if ((level(root, p, 1) == level(root, q, 1)) && !(isSibling(root, p, q)))
        return true;
    else
        return false;
}
