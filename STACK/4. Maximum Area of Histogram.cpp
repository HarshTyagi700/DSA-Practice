//https://leetcode.com/problems/largest-rectangle-in-histogram/
/*
Given an array of integers heights representing the histogram's bar height where the width of each bar 
is 1, return the area of the largest rectangle in the histogram.
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Input: heights = [2,4]
Output: 4

*/
vector<int> nearestSmallLeft(vector<int> &arr)
    {
        vector<int> ans;
        stack<pair<int,int>> s;
        for(int i=0;i<arr.size();i++)
        {
            if(s.empty())
            ans.push_back(-1);
            else{
                while(s.size()>0 && s.top().first>=arr[i])
                s.pop();
                
                if(s.size()==0)
                    ans.push_back(-1);
                else ans.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }    
        return ans;
    }
    
    vector<int> nearestSmallRight(vector<int> &arr)
    {
        vector<int> ans;
        stack<pair<int,int>> s;
        for(int i=arr.size()-1;i>=0;i--)
        {
            if(s.empty())
            ans.push_back(arr.size());
            else{
                while(s.size()>0 && s.top().first>=arr[i])
                s.pop();
                
                if(s.size()==0)
                    ans.push_back(arr.size());
                else ans.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }  
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> NSL_Index,NSR_Index;
        int ans=-1;
        NSL_Index=nearestSmallLeft(heights);
        NSR_Index=nearestSmallRight(heights);
        
        for(int i=0;i<heights.size();i++)
        {
            int temp=heights[i]*(NSR_Index[i] - NSL_Index[i] - 1);
            if(temp>ans)
                ans=temp;
        }
        return ans;
    }

    //Another Solution using single stack and single traversal
    //TC- O(N) SC- O(N)
    //here we'er calculating the area covered by heights[i] while popping it out from the stack
    //while popping it out we know it is being popped bcz an element smaller than it is goin' to be 
    //inserted so that will the it's rightSmaller
    //and one below that popped element would be leftSmaller(would be -1 is stack is empty())
    //that's how we can calculate the maxArea within one pass
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