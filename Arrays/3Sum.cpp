//https://leetcode.com/problems/3sum/
/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[1] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
*/
 vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<=n-3){
            int low=i+1,high=n-1;
            while(low<high){
                if(nums[low]+nums[high]==-nums[i]){
                    ans.push_back({nums[i],nums[low],nums[high]});
                    low++,high--;
                    while(low+1<n and nums[low-1]==nums[low])
                        low++;
                }
                else if(nums[low]+nums[high]<-nums[i]){
                    low++;
                    while(low+1<n and nums[low-1]==nums[low])
                        low++;
                }
                else{
                    high--;
                    while(high-1>=0 and nums[high]==nums[high+1])
                        high--;
                }
            }
            i++;
            while(i<=n-3 and nums[i-1]==nums[i]) i++;
        }
        return ans;
    }