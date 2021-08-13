#include<bits/stdc++.h>
using namespace std;
 // Definition for a binary tree node.
//Leetcode https://leetcode.com/problems/binary-tree-maximum-path-sum/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

    int Solve(TreeNode *root,int &res)
    {
        if(root==nullptr)
            return 0;
        int l=Solve(root->left,res);
        int r=Solve(root->right,res);
        int temp=max(l,r)+root->val;//for passing upward
        int ans=max(temp,l+r+root->val);//I can also be an answer lets see
        res=max(res,ans);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        Solve(root,res);
        return res;
    }
int main()
{
    struct TreeNode *root = new TreeNode(2);
    root->left=new TreeNode(1);
    root->right=new TreeNode(3);
    cout<<maxPathSum(root);
    

    return 0;
}

