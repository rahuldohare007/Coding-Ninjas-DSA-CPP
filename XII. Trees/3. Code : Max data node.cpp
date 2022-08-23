/*
Given a generic tree, find and return the node with maximum data. You need to return the node which is having maximum data.
Return null if tree is empty.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of
child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output contains the data of the node with largest data in the given tree.

Constraints:
Time Limit: 1 sec

Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
50
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

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
  
  //1. Recursion
    TreeNode<int> *max = new TreeNode<int>(root->data);
    for(int i=0; i<root->children.size(); i++)
    {
        TreeNode<int> *child = maxDataNode(root->children[i]);
        if(child->data > max->data)
              max = child;
    }
    return max;
  
  //2. Level wise
    TreeNode<int> *max = new TreeNode<int>(INT_MIN);
    queue<TreeNode<int>*> pn;
    pn.push(root);
    
    while(pn.size()!=0)
    {
        TreeNode<int>* front = pn.front();
        pn.pop();
        if(front->data > max->data)
           max = front;
            
        for(int i=0;i<front->children.size();i++)
        {
            pn.push(front->children[i]);
        }
    }
    return max;
}
