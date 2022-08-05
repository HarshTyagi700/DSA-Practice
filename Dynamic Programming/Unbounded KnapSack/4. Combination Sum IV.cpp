/*
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Example 2:

Input: nums = [9], target = 3
Output: 0
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 1000
All the elements of nums are unique.
1 <= target <= 1000
*/

/*
Approach -> We can take a number any number of times and we also have to check for different places it can be placed.
So, we'll have a vector to store how many number of ways are there to get a particular number(<=target) to memoize the solution
Try checking for all the possible path from a number and adding that to the sum, if sum exceeds our target then we'll return 0 from there.
Looping over all the nums in the vector will give us the total number of combination for getting the target.
*/

class Solution {
    private:
    vector<int> dp;
    int solve(vector<int>& nums,int sum, int target){
        if(sum==target)
            return 1;
        if(sum>target)
            return 0;
        if(dp[sum]!=-1) return dp[sum];
        int ways=0;
        for(int i=0;i<nums.size();i++){
            ways+=solve(nums,sum+nums[i],target);
        }
        return dp[sum]=ways;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int sum=0;
        dp.resize(target+1,-1);
        return solve(nums,sum,target);
    }
};
