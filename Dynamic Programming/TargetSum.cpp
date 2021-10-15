/* 
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
*/
int findTargetSumWays(vector<int>& nums, int target) {
          int sum;
        for(int x:nums)
            sum+=x;
        target=abs(target);//target can be -ve
        if(((sum+target)&1)||sum<target)//checking if sum of range and target is even or not and if target is greater than range
            return 0;
        int subsetSum=(sum+target)/2;
        // vector<vector<int>> T(nums.size() + 1 , vector<int> (subsetSum + 1,-1));
        int T[nums.size()+1][subsetSum+1];
        for(int i=0;i<nums.size()+1;i++)
            T[i][0]=1;
        for(int j=1;j<subsetSum+1;j++)
            T[0][j]=0;
        for(int i=1;i<=nums.size();i++)
            for(int j=0;j<=subsetSum;j++)
                /*If all the elements are 0 and we want a sum 0, for that we need j from 0. So that 0 can also be considered as sum of previous subset of i elements.
            */
            {
                if(nums[i-1]<=j)
                    T[i][j]=T[i-1][j]+T[i-1][j-nums[i-1]];
                else T[i][j]=T[i-1][j];
            }
       
        return T[nums.size()][subsetSum];
    }
