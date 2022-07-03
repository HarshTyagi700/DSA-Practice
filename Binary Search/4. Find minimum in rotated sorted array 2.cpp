
//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [1,3,5]
Output: 1
Example 2:

Input: nums = [2,2,2,0,1]
Output: 0
*/
//duplicates will also be there
 int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int minEle;
        int mid,start=0,end=n-1;
        int prev,next;
        while(start<end){
            mid=start+(end-start)/2;
            if(nums[mid]<nums[end])//mid can be the minimum
                end=mid;
            else if(nums[mid]>nums[end])//min will be  lying  after mid+1 means from here it was rotated
                start=mid+1;
            else end--;//if nums[mid]==nums[high] then we'll again check for mid by decrementing high
        }
        return nums[start];//can be nums[end] also 
    }