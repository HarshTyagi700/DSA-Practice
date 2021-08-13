#include<bits/stdc++.h>
using namespace std;
 
 int binarySearch(vector<int> &nums,int start,int end,int key)
 {
     if(end-start<=0)
     {
         if(nums[start]==key)
         return start;
         else return -1;
     }
    int mid=start+(end-start)/2;
    if(nums[mid]==key)
    return mid;
    else if(nums[mid]<key)
    return binarySearch(nums,mid+1,end,key);
    else 
    return binarySearch(nums,start,mid-1,key);
     
 }
 
 int findMin(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int minIndex;
        int N=nums.size();
        int mid,start=0,end=nums.size()-1;
        int prev,next;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            prev=(mid-1+N)%N;
            next=(mid+1)%N;
            if(nums[mid]<nums[prev]&&nums[mid]<nums[next])
                return minIndex=mid;
            else if(nums[mid]<nums[end])
                end=mid-1;
            else //if(nums[start]<nums[mid])
                start=mid+1;
        }
        cout<<minIndex<<'\n';
       return minIndex;
 }
 
 int searchSorted(vector<int> &nums, int target)
 {
     if(nums.size()==1)
        {
            if(nums[0]==target)
                return 0;
            else return -1;
        }
     int minIndex=findMin(nums);
     int res1=binarySearch(nums,minIndex,nums.size()-1,target);
     int res2=binarySearch(nums,0,minIndex,target);
     if(res1==res2)
     return res1;
     else if(res1==-1)
     return res2;
     else 
     return res1;
 }
 
 int main()
 {
     vector<int> nums={1,2,3,4,5,6,7,8,9,15,-5,-1,0};
     vector<int> nums2={1};
    //  cout<<binarySearch(nums,0,nums.size()-1,155);
    cout<<searchSorted(nums2,0);
     return 0;
     
 }
