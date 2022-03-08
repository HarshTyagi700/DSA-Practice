//https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int> *root){
    return !root->left && !root->right;
}
void addLeftBoundary(TreeNode<int> *node,vector<int> &res){
    while(node){
        if(!isLeaf(node)) res.push_back(node->data);
        if(node->left) node=node->left;
        else node=node->right;
    }
}
void addRightBoundary(TreeNode<int> *node,vector<int> &res){
    vector<int> tmp;
    while(node){
        if(!isLeaf(node)) tmp.push_back(node->data);
        if(node->right) node=node->right;
        else node=node->left;
    }
    for(int i=tmp.size()-1;i>=0;i--)
        res.push_back(tmp[i]);
}
void addLeaves(TreeNode<int> *node,vector<int> &res){
    if(isLeaf(node))
        res.push_back(node->data);
    if(node->left) addLeaves(node->left,res);
    if(node->right) addLeaves(node->right,res);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    addLeftBoundary(root->left,res);
    addLeaves(root,res);
    addRightBoundary(root->right,res);
    return res;
}
//TC-> O(H)  + O(H)  +O(N)
//Auxiliary SC-> O(N)
