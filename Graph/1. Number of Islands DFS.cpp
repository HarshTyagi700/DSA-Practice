//https://leetcode.com/problems/number-of-islands/
/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/


/*
We will have a visited 2D array and mark the positions as visited when we have visited them.
whenever we encounter a position which is not visited and is 1 then we'll make a dfs call
and mark all its neighbour which are 1 as visited and increment the count of islands by 1.
keep on doing it for all positions.
*/
class Solution {
private:
    void dfs(int i,int j,int m,int n,vector<vector<bool>> &vis,
            vector<vector<char>> &grid){
        if(i==m || j==n || i<0 || j<0 || grid[i][j]=='0')
            return;
        if(!vis[i][j]){
        vis[i][j]=true;
        dfs(i+1,j,m,n,vis,grid);
        dfs(i-1,j,m,n,vis,grid);
        dfs(i,j+1,m,n,vis,grid);
        dfs(i,j-1,m,n,vis,grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int islands=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] and grid[i][j]=='1'){
                    islands++;
                    dfs(i,j,m,n,vis,grid);
                }
            }
        }
        return islands;
    }
};