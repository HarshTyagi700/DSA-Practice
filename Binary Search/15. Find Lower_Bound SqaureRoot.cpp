//https://leetcode.com/problems/sqrtx/
/*
Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

 

Example 1:

Input: x = 4
Output: 2
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
*/

int mySqrt(int x) {
        if(x==0||x==1)
            return x;
        long long mid,l=1,h=x/2;
        int ans;
        while(l<=h){
            mid=l+(h-l)/2;
          long long sqrVal=mid*mid;
            if(sqrVal==x)
                return mid;
            else if(sqrVal<x)
            {
                ans=mid;//as i have to find lower bound this can be my answer
                l=mid+1;
            } 
            else h=mid-1;
        }
        return ans;
    }