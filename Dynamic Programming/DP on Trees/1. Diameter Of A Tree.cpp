//https://leetcode.com/problems/diameter-of-binary-tree/
/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 
*/

class Solution {
private:
    int solve(TreeNode *root,int &maxi)
    {
        if(root==nullptr)
            return 0;
        int lH=solve(root->left,maxi);
        int rH=solve(root->right,maxi);
        maxi=max(maxi,lH+rH);
        return 1+max(lH,rH);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        solve(root,maxi);
        return maxi;
        
    }
};