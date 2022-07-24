//https://leetcode.com/problems/minimum-window-substring/
/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        /*
        our approach will be to decrement count of char 
        while traversing a window (if it exists in map)
         and will check if that char's count has become zero 
         then we'll simply decrement count of unique chars
         When countUnique become 0 that means all chars in t 
         are now being matched with a window in s
         so that can be the answer 
         Next we'll start removing elements from left 
         (ith pointer) bcz that can also be the answer
        */
        if(s.length()<t.length())
            return "";
        map<char,int> mp;
        for(char ch:t)
            mp[ch]++;
        int countUnique=mp.size();
        int ansI=-1,ansJ=-1,ans=INT_MAX;
        int i=0,j=0,n=s.length();
        while(j<n){
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0) 
                    countUnique--;               
            }
            
            if(countUnique==0 ){
                if(j-i+1<ans){   
                ans=j-i+1;
                ansI=i;
                ansJ=j;
                }
                while(i<n and countUnique==0)
                {
                    if(mp.find(s[i])!=mp.end())
                    {
                        mp[s[i]]++;
                    if(mp[s[i]]==1)
                        countUnique++;
                    }
                     i++;   
                    if(j-i+1<ans and countUnique==0)
                    {   
                        ans=j-i+1;
                        ansI=i;
                        ansJ=j;
                        
                    }
                   
                }
        }
            j++;
        
    }
        if(ansI==-1) return "";
            else return s.substr(ansI,ansJ-ansI+1);
    }
};