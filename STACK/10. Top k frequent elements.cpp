//https://leetcode.com/problems/top-k-frequent-elements/
/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 
*/

vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> hashMap;//by default all key values will be zero.
        for(int i=0;i<nums.size();i++)
            hashMap[nums[i]]++;//O(N)
        priority_queue<pi,vector<pi>,greater<pi>> minh;
        for(auto i=hashMap.begin();i!=hashMap.end();i++) //O(N)
        {
            minh.push(make_pair(i->second,i->first));
            if(minh.size()>k)
                minh.pop();//O(NlogK)
        }
        while(!minh.empty())//logK
        {
            ans.push_back(minh.top().second);
            minh.pop();
        }
          return ans;
        
    }

    //better approach would be to minimize O(NlogK) part by pushing all element first and then retriving first k
    //O(logN+klogN)