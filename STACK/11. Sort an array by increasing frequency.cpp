//https://leetcode.com/problems/sort-array-by-increasing-frequency/
/*
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
*/  

 vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        vector<pi> temp;
      unordered_map<int,int> hashMap;
        for(int i=0;i<nums.size();i++)
            hashMap[nums[i]]++;
        
      priority_queue<pi,vector<pi>,greater<pi>> minh;
        for(auto i=hashMap.begin();i!=hashMap.end();i++)
            minh.push(make_pair(i->second,i->first));//here first frequency and then number
        
        while(!minh.empty())
        {
                temp.push_back({minh.top().second,minh.top().first});//here first number and then its frequency
                minh.pop();
        }
        sort(temp.begin(),temp.end(),compare);
        for(auto i=temp.begin();i!=temp.end();i++)
        {
            for(int j=1;j<=i->second;j++)
                ans.push_back(i->first);
        }
        return ans;
    }