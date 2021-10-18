/*
https://leetcode.com/problems/shortest-common-supersequence/

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"

*/
string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> t(str1.size()+1,vector<int>(str2.size()+1));
        // int t[str1.size()+1][str2.size()+1];
        string ans;
        for(int i=0;i<t.size();i++)
            t[i][0]=0;
        for(int j=1;j<t[0].size();j++)
            t[0][j]=0;
        
        for(int i=1;i<t.size();i++)
            for(int j=1;j<t[0].size();j++)
            {
                if(str1[i-1]==str2[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        
       int n=str1.size(),m=str2.size();
 
        while(n!=0&&m!=0)
        {
           // Can also be used to print LCS using only if condition for storing ans
            if(str1[n-1]==str2[m-1])//if chars are matching take them only once
            {
                ans.push_back(str1[n-1]);
                n--,m--;
            }
            else if(t[n-1][m]>t[n][m-1])//else if above row is giving max LCS includes below row's respective char and then move to above row
                ans.push_back(str1[n-1]),n--;
            else ans+=str2[m-1],m--;//else if previous column is giving max LCS take column's char and move to previous column
        }
        while(n!=0)//if n has not reached 0 that means more chars are left
            ans+=str1[n-1],n--;
        while(m!=0)//if m has not reached 0 that means more chars are left so include them as it is
            ans+=str2[m-1],m--;
        reverse(ans.begin(),ans.end());//now reverse the string to get the answer in right order
        return ans;
            
    }
