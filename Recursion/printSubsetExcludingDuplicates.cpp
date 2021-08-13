//https://leetcode.com/problems/subsets-ii/

void subSet(int index,vector<int> &nums,vector<int> out,vector<vector<int>> &ans,map<vector<int>,int> &Sets)
    {
        if(index==nums.size())
        { 
            sort(out.begin(),out.end());
          if(Sets.find(out)==Sets.end())
            { 
               ans.push_back(out);
               Sets.insert({out,1});
            }
            
            return;
        }
        subSet(index+1,nums,out,ans,Sets);
         out.push_back(nums[index]);
        subSet(index+1,nums,out,ans,Sets);
        
            
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<vector<int>,int> Sets;
         vector<vector<int>> ans;
        int index=0;
        vector<int> out;
        subSet(index,nums,out,ans,Sets);
        return ans;
    }
