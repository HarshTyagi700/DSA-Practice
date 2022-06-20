//https://leetcode.com/problems/partition-equal-subset-sum/
/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
*/
 bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int it:nums)
            sum+=it;
        if(sum%2==1)
            return false;
        sum/=2;
        vector<bool> prev(sum+1,false) , next(sum+1,false);
        
        prev[0]=true;
        for(int j=1;j<sum+1;j++)
            prev[j]=false;//filling for i==0
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(j==0)
                    next[j]=true;
                else if(i==0)
                    next[j]=false;
                else if(nums[i-1]<=j)
                    next[j]=prev[j] || prev[j-nums[i-1]];
                else next[j]=prev[j];
                    
            }
            prev=next;
        }
        return next[sum];
        
    }
