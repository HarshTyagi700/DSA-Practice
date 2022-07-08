//https://leetcode.com/problems/trapping-rain-water/
//Don't use STACK appraoch
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*/
/*
Approach 1 -> Individually calculating leftMax and rightMax for each index TC -> O(N^2)
Approach 2 -> prefixMax and suffixMax array TC-> O(3N) SC-> O(2N)
Appraoch 3 -> 2 pointer appraoch
*/

 int trap(vector<int>& height) {
        int leftMax=0,rightMax=0,left=0,right=height.size()-1;
        int totalWater=0;
        while(left<=right){

            if(height[left]<=height[right]){//means left will be the min of blocking water
                 if(height[left]>=leftMax)//if it's the maxLeft then water will not be stored
                leftMax=height[left];
                else  totalWater+=(leftMax-height[left]);//otherwise add this much amt of water
                left++;
            }
            else {//right is min for blocking water
                 if(height[right]>=rightMax)
                rightMax=height[right];
                else  totalWater+=(rightMax-height[right]);
                right--;
            } 
        }
        return totalWater;
        
    }