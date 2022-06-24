//https://leetcode.com/problems/construct-target-array-with-multiple-sums/
/*
You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :

let x be the sum of all elements currently in your array.
choose index i, such that 0 <= i < n and set the value of arr at index i to x.
You may repeat this procedure as many times as needed.
Return true if it is possible to construct the target array from arr, otherwise, return false.

 

Example 1:

Input: target = [9,3,5]
Output: true
Explanation: Start with arr = [1, 1, 1] 
[1, 1, 1], sum = 3 choose index 1
[1, 3, 1], sum = 5 choose index 2
[1, 3, 5], sum = 9 choose index 0
[9, 3, 5] Done
Example 2:

Input: target = [1,1,1,2]
Output: false
Explanation: Impossible to create target array from [1,1,1,1].
Example 3:

Input: target = [8,5]
Output: true
 

Constraints:

n == target.length
1 <= n <= 5 * 104
1 <= target[i] <= 109
*/
 
 //Recursive Solution
 bool isPossible(vector<int>& target) {
        long sum=0;
        int maxIdx=0;
        for(int i=0;i<target.size();i++){
            sum+=target[i];
            if(target[i]>target[maxIdx])
                maxIdx=i;
        }
        //value that was added to this maxIdx element 
        long diff=sum-target[maxIdx];
        if(diff==1||target[maxIdx]==1)
            return true;
        if(diff<1 || diff>target[maxIdx] || target[maxIdx]%diff==0)
            return false;
        target[maxIdx]%=diff;
        return isPossible(target);
    }


//Solution using max heap
  bool isPossible(vector<int>& target) {
        long sum=0;
        priority_queue<int> maxh;
        for(int i=0;i<target.size();i++){
            sum+=target[i];
            maxh.push(target[i]);
        }
        while(maxh.top()!=1)
        {
            //value that was added to this maxIdx element
            int topEle=maxh.top();
            maxh.pop();
            //finding out how much this element is greater
            long diff=sum-topEle;//subtracting this topEle from diff 
                                //will give us previous state
            if(diff==1)
             return true;
            if(diff<1 || diff>topEle || topEle%diff==0)
             return false;
            topEle%=diff;//taking remainder because topEle can be very large
            //so it will get subtracted everytime so it's better to take modulo 
            //of that
            sum=diff+topEle;//diff -> elements sum(excpet the max) so adding it to top
            //will give the new sum
            maxh.push(topEle%diff);//pushing the new element into the heap
        }
        return true;
    }