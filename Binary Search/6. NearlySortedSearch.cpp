//https://www.geeksforgeeks.org/search-almost-sorted-array/
#include<bits/stdc++.h>
using namespace std;

int nearlySortSearch(vector<int> nums,int key)
{
    if(nums.size()==1)
    {
        if(nums[0]==key)
        return 0;
    }
    int mid , start=0,end=nums.size()-1;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(key==nums[mid])
        return mid;
        if(start<mid&&nums[mid-1]==key)//checking for mid-1 idx if it exists
        return mid-1;
        if(end>mid&&nums[mid+1]==key)//checking mid+1 idx if it exists
        return mid+1;
        if(key<nums[mid])
            end=mid-2;
        else start=mid+2;
    }
    return -1;
    
}

int main()
{
    vector<int> nums={3, 2, 10, 4, 40};
    cout<<nearlySortSearch(nums,3)<<'\n';
    cout<<nearlySortSearch(nums,2)<<'\n';
    cout<<nearlySortSearch(nums,10)<<'\n';
    cout<<nearlySortSearch(nums,4)<<'\n';
    cout<<nearlySortSearch(nums,40)<<'\n';
    cout<<nearlySortSearch(nums,31)<<'\n';
    cout<<nearlySortSearch(nums,1)<<'\n';
    return 0;
}
