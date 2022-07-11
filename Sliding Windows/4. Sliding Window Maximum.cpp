//https://leetcode.com/problems/sliding-window-maximum/
/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 


*/
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //i will be maintaining a monotonic increasing queue
        //and will remove smaller elementss while pushing a bigger one
        deque<int> q;
        vector<int> maxInWindow;
        int j=0,i=0,n=nums.size();
        while(j<n){
            while(!q.empty() and q.back()<nums[j])
                q.pop_back();//i fon't need this
            //bcz nums[j] is the new max in that window
            q.push_back(nums[j]);
            if(j-i+1<k) j++;
            else{
                maxInWindow.push_back(q.front());
                if(q.front()==nums[i])
                    q.pop_front();
                i++,j++;
            }
        }
        return maxInWindow;
        
        
    }