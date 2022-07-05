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