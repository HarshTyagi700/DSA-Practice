//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
/*Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
*/
class Solution {
private:
    TreeNode* buildTree(vector<int>& inorder,int is,int ie,
                        vector<int>& postorder,int ps,int pe,
                        map<int,int> &inMap)
    {
        if(is>ie or ps>pe)
            return NULL;
        
        TreeNode* root=new TreeNode(postorder[pe]);
        
        int idxRoot=inMap[postorder[pe]];
        int nodesLeft=idxRoot-is;
        
        root->left=buildTree(inorder,is,idxRoot-1,
                             postorder,ps,ps+nodesLeft-1,inMap);
        root->right=buildTree(inorder,idxRoot+1,ie,
                             postorder,ps+nodesLeft,pe-1,inMap);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //map for storing indexes of nodes in inorder vector
        map<int,int> inMap;
        for(int i=0;i<inorder.size();++i)
            inMap[inorder[i]]=i;
        return buildTree(inorder,0,inorder.size()-1,
               postorder,0,postorder.size()-1,inMap);
    }
};
