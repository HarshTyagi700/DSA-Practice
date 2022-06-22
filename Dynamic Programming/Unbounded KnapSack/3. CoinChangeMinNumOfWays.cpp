/*

https://leetcode.com/problems/coin-change/
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
Example 4:

Input: coins = [1], amount = 1
Output: 1
Example 5:

Input: coins = [1], amount = 2
Output: 2
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 104
*/
//Recursive Code with Memoization
class Solution {
private:
    int minCoins(int amt,int i,vector<int>& coins,vector<vector<int>> &T)
    {
        if(amt==0)
            return 0;
        if(i<=0 and amt>0)
            return INT_MAX-1;
        if(i==1)
        {
            return (amt%coins[i-1]==0)?amt/coins[i-1]:INT_MAX-1;
        }
        if(T[i][amt]!=-1)
            return T[i][amt];
        if(coins[i-1]<=amt)
            return T[i][amt]=min(minCoins(amt,i-1,coins,T),1+minCoins(amt-coins[i-1],i,coins,T));
        return T[i][amt]=minCoins(amt,i-1,coins,T);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> T(n+1,vector<int> (amount+1,-1));
        int ans= minCoins(amount,coins.size(),coins,T);
            return ans==INT_MAX-1?-1:ans;
    }
};


//Bottom-Up DP
int coinChange(vector<int>& coins, int amount) {
        int T[coins.size()+1][amount+1];
        for(int i=0;i<=coins.size();i++)
            T[i][0]=0;
        for(int j=1;j<=amount;j++)
        {
            T[0][j]=INT_MAX-1;
            if(j%coins[0]==0)//if completely divisible then put quotient
                T[1][j]=j/coins[0];
            else T[1][j]=INT_MAX-1; //otherwise put INT_MAX
        }
        for(int i=2;i<=coins.size();i++)
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]<=j)
                    T[i][j]=min(T[i][j-coins[i-1]]+1,T[i-1][j]);
                else T[i][j]=T[i-1][j];
            }
        if(T[coins.size()][amount]==INT_MAX-1)//if INT_MAX coins required that means it is not possible to generate that amount from the given coins
            return -1;
        else return T[coins.size()][amount];
            
    }
