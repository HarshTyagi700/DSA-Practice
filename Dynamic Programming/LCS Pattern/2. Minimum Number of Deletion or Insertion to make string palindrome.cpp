/*
https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/submissions/

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
Example 4:

Input: s = "g"
Output: 0
Example 5:

Input: s = "no"
Output: 1

*/
//First Calculate LCS with reverse string and then return string.length - LCS
int minInsertions(string s) {
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
        return s.size()-T[s.size()&1][s.size()];
    }
