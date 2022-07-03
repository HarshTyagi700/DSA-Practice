//https://leetcode.com/problems/find-peak-element/

/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
*/
int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;//index
        int mid,low=0,high=n-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(mid>0 and mid< n-1 ){//means neighbor elements exists
                if(nums[mid-1]<nums[mid] and nums[mid+1]<nums[mid])
                    return mid;
                else if(nums[mid-1]>nums[mid])
                    high=mid-1;
                else low=mid+1;
            }
            //any one or both of neighbors are out of bound
            else{
                if(mid==0 and nums[0]>nums[1])
                    return 0;
                else return high;
            }
            //returning high because consider case of [1,2]
            //here mid would be 0
            //but answer lies at high
        }
        return -1;
    }