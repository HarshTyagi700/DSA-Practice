//https://leetcode.com/problems/interleaving-string/
/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
*/

//TC- O(M*N) if all chars are same and matching
class Solution {
private:
    unordered_map<string,bool> mp;
    bool solve(string &s1, string &s2, string &s3,int l1,int l2,int l3,int p1,int p2,int  p3){
        //if s3 is completed and p1 and p2 also reached end then we'll return true
        if(p3==l3){
            return (p1==l1 && p2==l2)?true:false;
        }
        //making key for storing for future use
        string key=to_string(p1)+'_'+to_string(p2)+'_'+to_string(p3);
        if(mp.find(key)!=mp.end())
            return mp[key];
        
        if(p1==l1)//if first string is completed the we'll only check for s2's result
            return mp[key]=s2[p2]==s3[p3]?solve(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1):false;
        if(p2==l2)//vice-versa
            return mp[key]=s1[p1]==s3[p3]?solve(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1):false;
        
        //now if char from s3 is matching with boththen we have two option
        //we'll check both and take the required result
        bool first=false,second=false;
        if(s1[p1]==s3[p3])//taking from s1
            first=solve(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1);
        if(s2[p2]==s3[p3])//taking from s2
            second=solve(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1);
        return mp[key]=first || second;//if anyone results true we return that
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.length(),l2=s2.length(),l3=s3.length();
        //if length is not equal then we'll return false
        if(l1+l2!=l3)
            return false;
        //0 is the ptr we'll match chars
        return solve(s1,s2,s3,l1,l2,l3,0,0,0);
    }
};