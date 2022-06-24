/*
https://leetcode.com/problems/longest-palindromic-subsequence/

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
*/
//Space Complexity - > O(N)
//Time Complexity - > O(N^2)
 int longestPalindromeSubseq(string s) {
        string revS=string(s.rbegin(),s.rend());
        int T[2][s.size()+1];
        for(int i=0;i<=s.size();i++)
            for(int j=0;j<=s.size();j++)
        {
                if(!i||!j)
                T[i&1][j]=0;
                else if(s[i-1]==revS[j-1])
                  T[i&1][j]=1+T[(i-1)&1][j-1];
                else T[i&1][j]=max(T[(i-1)&1][j],T[i&1][j-1]);
        }
        return T[s.size()&1][s.size()];
    }
