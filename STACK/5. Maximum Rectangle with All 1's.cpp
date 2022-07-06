//https://leetcode.com/problems/maximal-rectangle/
/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:

Input: matrix = [["0"]]
Output: 0

Example 3:

Input: matrix = [["1"]]
Output: 1
*/
 int largestRectangleArea(vector<int>& heights) {
       stack<int> st;//for storing idx in linear increasing fashion of ht
        int maxArea=0,n=heights.size();
        for(int i=0;i<=n;i++){
                while(!st.empty() && 
              (i==n ||heights[st.top()]>=heights[i])){
                    int rightSmaller=i;
                    int hT=heights[st.top()];
                    st.pop();
                    int leftSmaller=(!st.empty()?st.top():-1);
                    maxArea=max(maxArea,hT*(rightSmaller-leftSmaller-1));
                }           
               st.push(i);               
            }
      return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
      vector<int> heights;
        for(int j=0;j<matrix[0].size();j++)
            heights.push_back(matrix[0][j]-'0');
        int maxArea=0;
        maxArea=largestRectangleArea(heights);
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;
            }
            maxArea=max(maxArea,largestRectangleArea(heights));
        }
        return maxArea;
    }