//https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1/#
/*
Given an array of n elements, where each element is at most k away from its target position, you need to sort the array optimally.

Example 1:

Input:
n = 7, k = 3
arr[] = {6,5,3,2,8,10,9}
Output: 2 3 5 6 8 9 10
Explanation: The sorted array will be
2 3 5 6 8 9 10
Example 2:

Input:
n = 5, k = 2
arr[] = {3,1,4,2,5}
Output: 1 2 3 4 5 
Note: DO NOT use STL sort() function for this question.

Your Task:
You are required to complete the method nearlySorted() which takes 3 arguments and returns the sorted array.

Expected Time Complexity : O(nlogk)
Expected Auxilliary Space : O(n)
*/
vector <int> nearlySorted(int arr[], int n, int k){
       priority_queue<int,vector<int>,greater<int>> minh;
       vector<int> nums(n);
       int i=0;
       //first pushing k elements in min heap
       //because we want min element at the top
       while(i<=k)
       minh.push(arr[i++]);
       int j=0;//index for pushing in ans array
       while(j<n or i!=n){
           nums[j++]=minh.top();
           minh.pop();
           if(i!=n)//to avoid overflow
           minh.push(arr[i++]);
       }
     
       return nums;
    }