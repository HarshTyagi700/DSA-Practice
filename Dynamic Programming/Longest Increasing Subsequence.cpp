int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        dp[0]=1;
        int maxLength=1;
        for(int i=1;i<nums.size();i++)
        {
            int max=0;
            for(int j=i-1;j>=0;j--){
            
                if(nums[j]<nums[i])
                {
                 if(max<dp[j])
                     max=dp[j];
                }
                dp[i]=max+1;
                if(maxLength<dp[i])
                maxLength=dp[i];
            }
        }
        return maxLength;
    }
