//https://leetcode.com/problems/binary-tree-right-side-view/
/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
*/

//take a value as level and increment it whenever that level's right has been found
//then make a dfs call for right node first and then left side node
//ans.size() can be used for checking level
//at starting it's level(0) will match currLevel(0)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        if(!root) return rightView;
        dfs(root,0,rightView);
        return rightView;
    }
private:
    void dfs(TreeNode*node,int level,vector<int> &ans){
        if(node==NULL) return;
        if(level==ans.size())
            ans.push_back(node->val);
        dfs(node->right,level+1,ans);
        dfs(node->left,level+1,ans);
    }
};