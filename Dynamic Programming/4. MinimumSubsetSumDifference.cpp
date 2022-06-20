//https://leetcode.com/problems/last-stone-weight-ii/
/*
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose any two stones and smash them together. Suppose the stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the smallest possible weight of the left stone. If there are no stones left, return 0.

 

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0, so the array converts to [1], then that's the optimal value.
Example 2:

Input: stones = [31,26,33,21,40]
Output: 5
Example 3:

Input: stones = [1,2]
Output: 1
 

Constraints:

1 <= stones.length <= 30
1 <= stones[i] <= 100
*/
//This problem is same as minimum subset sum difference dividing the array into two parts such that subtracting or colliding in this case makes the total minimum.
int lastStoneWeightII(vector<int>& stones) {
     int range=0;
        for(auto  i:stones)
            range+=i;
        int n=stones.size();
        bool T[n+1][(range/2)+1];
        memset(T,false,sizeof T);
        for(int i=0;i<=n;i++)
            T[i][0]=true;
        for(int j=1;j<=range/2;j++)
            T[0][j]=false;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=range/2;j++)
            {
                if(stones[i-1]<=j)
                    T[i][j]=T[i-1][j]||T[i-1][j-stones[i-1]];
                else T[i][j]=T[i-1][j];
            }
        vector<int> possibleSums;
        for(int j=0;j<=range/2;j++)
        {
            if(T[n][j]==true)
                possibleSums.push_back(j);
        }
        int mn=INT_MAX;
        for(int i=0;i<possibleSums.size();i++)
            mn=min(mn,range-2*possibleSums[i]);
        return mn;
    }           
