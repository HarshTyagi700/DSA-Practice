//https://leetcode.com/problems/subsets-ii/
class Solution {
private:
    void solve(int idx,vector<int>& nums,vector<int> out,
               vector<vector<int>> &ans,set<vector<int>> &Set){
        if(idx==nums.size()){
            if(Set.find(out)==Set.end()){
                Set.insert(out);
                ans.push_back(out);
            }
            return ;
        }
        solve(idx+1,nums,out,ans,Set);
        out.push_back(nums[idx]);
        solve(idx+1,nums,out,ans,Set);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       set<vector<int>> Set;
       vector<vector<int>> ans;
        vector<int> out;
        int idx=0;
        sort(nums.begin(),nums.end());
        solve(idx,nums,out,ans,Set);
        return ans;
    }
};