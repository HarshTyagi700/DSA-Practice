//https://leetcode.com/problems/longest-consecutive-sequence/
/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/
 int longestConsecutive(vector<int>& nums) {
       set<int> hashSet;
        int longestStreak=0;
        for(int i:nums)
            hashSet.insert(i);
        for(int i:nums){
            if(hashSet.find(i-1)!=hashSet.end())
                continue;//we'll not start from here as one less than this 
            //already exist so in the next or previous turn we will take
            //or must have taken it
            else{//now since this can be the starting as 1 less than it doesn't exist
            //we will check for the longestStreak this num can give
            //by checking each consecutive number in set
                int currStreak=1;
                int num=i;
                while(hashSet.find(num+1)!=hashSet.end())
                    currStreak++,num++;
                longestStreak=max(longestStreak,currStreak);
            }
        }
        return longestAns;
    }