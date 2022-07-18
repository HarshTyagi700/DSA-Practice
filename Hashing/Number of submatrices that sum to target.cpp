//https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

/*

Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

 

Example 1:


Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
Example 3:

Input: matrix = [[904]], target = 0
Output: 0
*/

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int count=0;
        //we'll make prefix sum for each row
        for(int i=0;i<m;i++)
            for(int j=1;j<n;j++)
                matrix[i][j]+=matrix[i][j-1];
        
        unordered_map<int,int> mp;
        //now we'll traverse the matrix keeping different startCols
        //and checking every possibility of matrix sum there
        //we'll keep a cleared map every time we start with newCol
        for(int startCol=0;startCol<n;startCol++)
            for(int currCol=startCol;currCol<n;currCol++){
                mp.clear();
                mp[0]=1;
                int sum=0;
                for(int currRow=0;currRow<m;currRow++){
                    sum+=(matrix[currRow][currCol]-
                          (startCol>0?matrix[currRow][startCol-1]:0));
                    if(mp.find(sum-target)!=mp.end())
                        count+=mp[sum-target];
                    mp[sum]++;
                }
            }
        
        return count;
    }