// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
/*
Given an array arr[] of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7

Example 1:

Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
       sum = 10
Output: 3
Explanation: {2, 3, 5}, {2, 8}, {10}
Example 2:
Input: N = 5, arr[] = {1, 2, 3, 4, 5}
       sum = 10
Output: 3
Explanation: {1, 2, 3, 4}, {1, 4, 5}, 
             {2, 3, 5}

Your Task:  
You don't need to read input or print anything. Complete the function perfectSum() which takes N, array arr[] and sum as input parameters and returns an integer value

Expected Time Complexity: O(N*sum)
Expected Auxiliary Space: O(N*sum)

Constraints:
1 ≤ N*sum ≤ 106
0<=arr[I]<=106

*/

int perfectSum(int arr[], int n, int sum)
	{
	    int mod=1e9+7;
        int T[n+1][sum+1];///this table will store how many ways are there to have j as sum using values till n-1 in the array.
        for(int i=0;i<n+1;i++)
        T[i][0]=1;
        for(int j=1;j<sum+1;j++)
        T[0][j]=0;
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                T[i][j]=(T[i-1][j-arr[i-1]]%mod+T[i-1][j]%mod)%mod;
                else T[i][j]=T[i-1][j];
            }
        }
        // for(int i=0;i<n+1;i++)
        // {
        //     for(int j=0;j<sum+1;j++)
        //     {
        //         cout<<T[i][j]<<" ";
        //     }
        //     cout<<'\n';
            
        // }
        return T[n][sum]%mod;
	}
