/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
         if(root==NULL)
            return 0;
        int leftHeight=0,rightHeight=0;
        if(root->left!=NULL){
            leftHeight=minDepth(root->left);
        }
        if(root->right!=NULL)
        {
            rightHeight=minDepth(root->right);
        }
        if(root->left==NULL&&root->right!=NULL)
            return rightHeight+1;
        if(root->right==NULL&&root->left!=NULL)
            return leftHeight+1;
            
        return min(leftHeight,rightHeight)+1;
        
        // if(leftHeight<rightHeight)
        // {
        //     return leftHeight+1;
        // }
        // else return rightHeight+1;  
    }
};

/* 
            2
        null    3
             null    4
                        5
                            6
*/
