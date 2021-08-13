//https://leetcode.com/problems/subsets/

 void subSet(int index,vector<int> &nums,vector<int> out,vector<vector<int>> &ans)
    {
        if(index==nums.size())
        {
            ans.push_back(out);
            return;
        }
        subSet(index+1,nums,out,ans);
         out.push_back(nums[index]);
        subSet(index+1,nums,out,ans);
        
            
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int index=0;
        vector<int> out;
        subSet(index,nums,out,ans);
        return ans;
        
        
    }
