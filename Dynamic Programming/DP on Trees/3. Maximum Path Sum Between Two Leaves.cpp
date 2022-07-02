//https://practice.geeksforgeeks.org/problems/maximum-path-sum/1/#
/*
Given a binary tree in which each node element contains a number.
 Find the maximum possible path sum from one leaf node to another leaf node.
*/
//1 8 6 -7 -10 -9
    //5 N 6 -5 5
    //TCs to see
    //same as Path sum but we also need to consider that only path through leaf should be taken in answer

class Solution {
private:
int solve(Node *root, int &maxi){
    if(root==NULL)
    return 0;
    if(!root->left and !root->right)
    return root->data;
    
    int leftSum=solve(root->left,maxi);
    int  rightSum=solve(root->right,maxi);
    
    if(root->left and root->right)//here the node can be the answer since it has both left and right nodes and leaf as well
    {
       maxi=max(maxi,root->data+leftSum+rightSum); 
       return root->data+max(leftSum,rightSum);//for next computation taking the max of two paths through it
    }
    
    //now it can also happen that it has only 1 node below it 
    //so if we return max (left,right) and ans is negative from that single node then it would take the
    //0 as the maximum returned by the null node
    //so we have to separate those cases
    if(!root->left)
        return root->data+rightSum;
    else return root->data+leftSum;
    
}
public:
    int maxPathSum(Node* root)
    {
        int maxi=INT_MIN;
        int tempAns=solve(root,maxi);
        if(!root->left || !root->right)
            maxi=max(maxi,tempAns);
        return maxi;            
    }
};