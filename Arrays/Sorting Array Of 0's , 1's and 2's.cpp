//https://leetcode.com/problems/sort-colors/
void sortColors(vector<int>& nums) {
        int mid=0,low=0,high=nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
                swap(nums[low++],nums[mid++]);
            else if(nums[mid]==2)
                swap(nums[mid],nums[high--]);
            else mid++;  
        }
    }
