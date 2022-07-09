//https://leetcode.com/problems/find-k-closest-elements/
/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
*/
//NOT the best approach
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxh;
        int diff;
        vector<int> closeNums;
        for(int i:arr)
        {
            diff=abs(x-i);
            maxh.push(make_pair(diff,i));
            if(maxh.size()>k)
                maxh.pop();
        }
        while(maxh.empty()==false)
        {
            closeNums.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(closeNums.begin(),closeNums.end());
        return closeNums;
        
    }
//Another approach
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=size(arr);
        int mid,low=0,high=n-1;
        vector<int> closeEle;
        
        while(low<=high){
            mid=low+(high-low)/2;
            if(arr[mid]==x)
                break;
            else if(arr[mid]<x)
                low=mid+1;
            else high=mid-1;
        }
        if(mid>=1)
         low=mid-1, high=mid;
        else low=mid,high=mid+1;
        while(low>=0 and high<=n-1 and k--){
            if(abs(x-arr[low])<=abs(x-arr[high]))
            {
                closeEle.push_back(arr[low--]);
            }
            else closeEle.push_back(arr[high++]);
        }
        while(k>0 and low>=0){
            closeEle.push_back(arr[low--]);
            k--;
        }
        while(k>0 and high<=n-1){
            closeEle.push_back(arr[high++]);
            k--;
        }
        sort(closeEle.begin(),closeEle.end());
        return closeEle;
        
    }