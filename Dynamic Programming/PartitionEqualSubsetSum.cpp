 bool canPartition(vector<int>& nums) {
       int sum=0;
        for(int i:nums)
            sum+=i;
        if(sum%2!=0)
            return false;
        sum/=2;
        bool t[nums.size()+1][sum+1];
        for(int i=0;i<nums.size()+1;i++)
            t[i][0]=true;
        for(int j=1;j<sum+1;j++)
            t[0][j]=false;
        for(int i=1;i<nums.size()+1;i++)
         for(int j=1;j<sum+1;j++)
         {
             if(nums[i-1]<=j)
             t[i][j]=t[i-1][j]||t[i-1][j-nums[i-1]];
             else t[i][j]=t[i-1][j];
         }
        return t[nums.size()][sum];
    }
