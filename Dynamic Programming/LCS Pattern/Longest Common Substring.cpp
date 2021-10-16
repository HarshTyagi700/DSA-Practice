/*
https://leetcode.com/problems/maximum-length-of-repeated-subarray/
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

 

Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100
*/
 int findLength(vector<int>& nums1, vector<int>& nums2) {
        int t[nums1.size()+1][nums2.size()+1];
        int maxLength=-1;
        for(int i=0;i<=nums1.size();i++)
            t[i][0]=0;
        for(int j=1;j<=nums2.size();j++)
            t[0][j]=0;
        for(int i=1;i<=nums1.size();i++)
            for(int j=1;j<=nums2.size();j++)
            { 
                if(nums1[i-1]==nums2[j-1])//adding only when string matches 
                    t[i][j]=1+t[i-1][j-1];
                else t[i][j]=0;//otherwise mark all longest substring till here is zero bcz there would be some char/s which doesn't match and break the substring
                if(maxLength<t[i][j])//checking if we've got maxLength on this indexes and updating it if it is
                    maxLength=t[i][j];
            }
        return maxLength;
    }
