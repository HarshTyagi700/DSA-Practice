/*
https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

Example 1:

Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
Explaination: There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. 
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.

Example 2:

Input: N = 4
arr = {10, 30, 5, 60}
Output: 4500
Explaination: The matrices have dimensions 
10*30, 30*5, 5*60. Say the matrices are A, B 
and C. Out of all possible combinations,the
most efficient way is (A*B)*C. The 
number of multiplications are -
10*30*5 + 10*5*60 = 4500.

Your Task:
You do not need to take input or print anything. Your task is to complete the function matrixMultiplication() which takes the value N and the array arr[] as input parameters and returns the minimum number of multiplication operations needed to be performed.


Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(N2)


Constraints: 
2 ≤ N ≤ 100
1 ≤ arr[i] ≤ 500
*/
class Solution{
public:
    int T[105][105];
    int solve(int* arr,int i,int j)
    {
        if(i==j)
            return 0;
        if(T[i][j]!=-1)
        return T[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int tempAns=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            if(tempAns<ans)
                ans=tempAns;
        }
        return T[i][j]=ans;
            
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(T,-1,sizeof T);
        return solve(arr,1,N-1);
    }
};

//Recursive Solution with Memoization
//https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1/#
class Solution{
    private:
    
    int findMinOps(int arr[],int i,int j, vector<vector<int>> &T)
    {
        if(i>=j)
        return 0;
        int minAns=INT_MAX;
        int tempAns;
        if(T[i][j]!=-1)
        return T[i][j];
        for(int k=i;k<=j-1;k++)
        {
            int tempAns=findMinOps(arr,i,k,T)+arr[i-1]*arr[k]*arr[j]+
                        findMinOps(arr,k+1,j,T);
            minAns=min(tempAns,minAns);
        }
        return T[i][j]=minAns;
        
        
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> T(N+1,vector<int> (N+1,-1));
        return findMinOps(arr,1,N-1,T);
        
    }
};


//Tabulation Method Bottom-Up DP
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
//     vector<vector<int>> dp(N,vector<int>(N,-1));
    int dp[N][N];//we've to run only till N-1
    for(int i=1;i<=N-1;i++)
        dp[i][i]=0;//if there's only one matrix then ops =0
   
    for(int i=N-1;i>=1;i--)//do reverse of recursion there we were going from 1->N-1
    {
        for(int j=i+1;j<=N-1;j++)//here's a catch j can never be less than i so we'll start from i+1
        {
            int minAns=INT_MAX;
           for(int k=i;k<=j-1;k++)//trying out all possible partitions from here
        {
            int tempAns=dp[i][k]+arr[i-1]*arr[k]*arr[j]+
                        dp[k+1][j];//if we break at k then tempAns would be this
            minAns=min(tempAns,minAns);//taking minAns till now
        }
            dp[i][j]=minAns;//this is the min ans that we can get for dp[i][j] 
       
        }
    }
     return dp[1][N-1];//return the answer at top-right.
    
}
