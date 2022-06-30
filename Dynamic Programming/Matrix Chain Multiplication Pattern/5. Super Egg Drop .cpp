//https://leetcode.com/problems/super-egg-drop/
/*
    You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

 

Example 1:

Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
Example 2:

Input: k = 2, n = 6
Output: 3
Example 3:

Input: k = 3, n = 14
Output: 4
*/
class Solution {
public:
    int solve(int e,int f,vector<vector<int>> &dp){
         if(f==0||f==1||e==1)
            return f;      
        if(dp[e][f]!=-1)
            return dp[e][f];
        int minMoves=10004;
        int l=1,h=f;
        while(l<=h)
        {
            
            int broken,notBroken,mid=(l+h)/2;
            if(dp[e-1][mid-1]!=-1)
                broken=dp[e-1][mid-1];
            else broken=solve(e-1,mid-1,dp);
            
            if(dp[e][f-mid]!=-1)
                notBroken=dp[e][f-mid];
            else notBroken=solve(e,f-mid,dp);
            
            int tempAns=1+max(broken,notBroken);
            minMoves=min(minMoves,tempAns);
            
            if(broken<notBroken)
                l=mid+1;
            else h=mid-1;
            
        }
        return dp[e][f]=minMoves;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return solve(k,n,dp);
       
    }
};