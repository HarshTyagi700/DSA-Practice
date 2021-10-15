//https://practice.geeksforgeeks.org/problems/rod-cutting0840/1#
/*
Given a rod of length N inches and an array of prices, price[] that contains prices of all pieces of size smaller than N. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

 

Example 1:

Input:
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output:
22
Explanation:
The maximum obtainable value is 22 by
cutting in two pieces of lengths 2 and 
6, i.e., 5+17=22.
Example 2:

Input:
N=8
Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
Output: 24
Explanation: 
The maximum obtainable value is 
24 by cutting the rod into 8 pieces 
of length 1, i.e, 8*3=24. 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function cutRod() which takes the array A[] and its size N as inputs and returns the maximum price obtainable.


Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 1000
1 ≤ Ai ≤ 105
*/
int cutRod(int price[], int n) {
        int T[n+1][n+1];//[price.size][N+1]
        memset(T,-1,sizeof T);
        for(int j=0;j<=n;j++)//if price array doesn't contain any value
        T[0][j]=0;
        for(int i=1;i<=n;i++)//if rod length is 0
        T[i][0]=0;
        for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
         {
             if(i<=j)
             T[i][j]=max(T[i-1][j],price[i-1]+T[i][j-i]);
             else T[i][j]=T[i-1][j];
         }
         return T[n][n];
        
        
    }
