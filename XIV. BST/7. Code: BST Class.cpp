/*
Implement the BST class which includes following functions -

1. insert -
Given an element, insert that element in the BST at the correct position. If element is equal to the data of the node, insert it in the left subtree.

2. search
Given an element, find if that is present in BST or not. Return true or false.

3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.

4. printTree (recursive) -
Print the BST in in the following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y
where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.
*/ 

/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/

class BST {
    BinaryTreeNode<int>* root;
    
   public:
    BST() { 
        root = NULL;
    }
	
    ~BST() {
		delete root;
	}
	/*----------------- Public Functions of BST -----------------*/

    private:
    bool search(int data,BinaryTreeNode<int>* node){
        if(node == NULL)
            return false;
        if(node->data == data)
            return true;
        
        bool ans;
        if(data < node->data)
            ans = search(data, node->left);
        else
            ans = search(data, node->right);
        
        return ans;
    }
    
    BinaryTreeNode<int>* ins(int data,BinaryTreeNode<int>* node){
        
        if(node == NULL){
            BinaryTreeNode<int>* inode = new BinaryTreeNode<int>(data);
            return inode;
        }
        if(data > node->data)
            node->right = ins(data, node->right);
        else
            node->left = ins(data, node->left);
        
        return node;
    }
    
    BinaryTreeNode<int>* findMin(BinaryTreeNode<int>* node){
        if(node->left == NULL)
            return node; 
        return findMin(node->left);
    }
    
    BinaryTreeNode<int>* del(int data,BinaryTreeNode<int>* node){
        
        if(node == NULL)
            return NULL;
        
        if (data > node->data)
            node->right = del(data, node->right);
        else if(data < node->data)
            node->left = del(data, node->left);
        else{
            //If node is leaf
            if(node->left==NULL && node->right==NULL){
                delete node;
                return NULL;
            }
            else if(node->left == NULL){
                BinaryTreeNode<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if(node->right == NULL){
                BinaryTreeNode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else{
                BinaryTreeNode<int>* minnode = findMin(node->right);
                
                node->data = minnode->data;
                node->right = del(minnode->data, node->right);
                return node;
                
            }   
        }
        
        return node;
    }
    void pr(BinaryTreeNode<int>* node){
        if(node == NULL)
            return;
        
        cout<<node->data<<":";
        
        if(node->left != NULL)
            cout<<"L:"<<node->left->data<<",";
        if(node->right != NULL)
            cout<<"R:"<<node->right->data;
        cout<<endl;
        
        pr(node->left);
        pr(node->right);
    }
    
    public:
    void remove(int data) { 
        this->root = del(data,this->root); 
    }

    void print() { 
        pr(root);
    }

    void insert(int data) { 
        this->root = ins(data,this->root);
    }

    bool search(int data) {
		    return search(data,root);
    }
};
