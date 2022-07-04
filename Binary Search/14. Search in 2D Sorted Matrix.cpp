//https://leetcode.com/problems/search-a-2d-matrix/
/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //starting from top-right corner
        int i=0,j=matrix[0].size()-1;
        
        //marking constrains for indexes
        while(i>=0 && i<matrix.size() && j>=0 && j<matrix[0].size())
        {
            if(matrix[i][j]==target)
                return true;
            
            //if the target is less then we'll decrement j 
            if(matrix[i][j]>target)
                j--;
            
            //if target is more the we'll increment i
            else i++;
        }
        //TC -> O(max(m,n))
        return false;
        
    }