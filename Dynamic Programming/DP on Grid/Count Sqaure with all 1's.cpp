//https://leetcode.com/problems/count-square-submatrices-with-all-ones/
/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
*/
int countSquares(vector<vector<int>>& matrix) {
       int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        int totalSquares=0;
        //fill first row and column
        for(int i=0;i<m;i++){
            if(matrix[i][0]==1){
                dp[i][0]=1;
                totalSquares++;
            }    
        }
        //don't count matrix[0][0] twice
         for(int j=1;j<n;j++){
            if(matrix[0][j]==1){
                dp[0][j]=1;
                totalSquares++;
            }    
        }
             
        
        //now we'll take min of right-up three corners 
        //and will add 1 only if that cell is 1
        //otherwise there is no square ending there
        for(int i=1;i<m;i++)
        {
           for(int j=1;j<n;j++){
               if(matrix[i][j]==1){
                   int minSq=min(dp[i-1][j-1],
                                 min(dp[i-1][j],dp[i][j-1]));
                   dp[i][j]=minSq+1;
                   totalSquares+=dp[i][j];
               }
           } 
        }
 
        return totalSquares;
    }