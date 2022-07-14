//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 
*/
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;// nodeVal->idx
        //storing inorder idx bcz it will tell me 
        //how many nodes are in left and right
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        TreeNode *root=buildTree(preorder,0,preorder.size()-1,
                                inorder,0,inorder.size()-1,mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder,int preStart,int preEnd,
                        vector<int>& inorder,int inStart,int inEnd,
                       unordered_map<int,int> &mp)
    {
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode *root=new TreeNode(preorder[preStart]);
        int idxRoot=mp[root->val];
        int numsLeft=idxRoot-inStart;
        
        root->left=buildTree(preorder,preStart+1,preStart+numsLeft,
                            inorder,inStart,idxRoot-1,mp);
        root->right=buildTree(preorder,preStart+numsLeft+1,preEnd,
                            inorder,idxRoot+1,inEnd,mp);
        return root;
    }