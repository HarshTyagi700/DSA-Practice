//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/
bool search(vector<int>& nums, int target) {
       int low=0,high=nums.size()-1,mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]==target or nums[low]==target or nums[high]==target)//found the target
                return true;
            //if all three values are equal that means we
            //have to check for next indexes
            //kinda linear search
            if(nums[low]==nums[mid] && nums[mid]==nums[high])
            {
                low++;
                high--;
                continue;
            }
            
            //means left part is sorted
            if(nums[low]<=nums[mid])
            {
                //check where our target lies
                if(nums[mid]>target and nums[low]<=target)
                {
                    high=mid-1;
                }
                else low=mid+1;
            }
            //right part is sorted
            else {
                 if(nums[mid]<target and target<=nums[high])
                {
                    low=mid+1;
                }
                else high=mid-1;
            }
        }
        return false;
    }