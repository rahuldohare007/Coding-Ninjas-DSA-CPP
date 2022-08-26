/*
Given a generic tree, find and return the node with second largest value in given tree.

Note: Return NULL if no node with required value is present.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of 
child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output contains data of the node with second largest data.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40
*/

/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

void secondLargestUtil(TreeNode<int>* root, TreeNode<int>** first, TreeNode<int>** second)
{
    if (root == NULL)
        return;
 
    // If first is NULL, make root equal to first
    if (!(*first))
        *first = root;
 
    // if root is greater than first then second
    // will become first and update first equal
    // to root
    else if (root->data > (*first)->data) {
        *second = *first;
        *first = root;
    }
    // if second is null, then
    // update first only if root is less than first
    else if (!(*second)) {
        if (root->data < (*first)->data) {
            *second = root;
        }
    }
    // If root is less than first but greater than second
    else if (root->data < (*first)->data && root->data > (*second)->data)
        *second = root;
 
    // number of children of root
    int numChildren = root->children.size();
 
    // recursively calling for every child
    for (int i = 0; i < numChildren; i++)
        secondLargestUtil(root->children[i], first, second);
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    TreeNode<int>* second = NULL;
 
    // first will store the largest value in the tree
    TreeNode<int>* first = NULL;
 
    // calling the helper function
    secondLargestUtil(root, &first, &second);
 
    if (second == NULL)
        return NULL;
 
    // return the second largest element
    return second;
}
