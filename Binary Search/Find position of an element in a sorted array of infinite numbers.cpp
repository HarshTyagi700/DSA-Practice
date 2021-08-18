#include <iostream>
using namespace std;
 int binarySearch(int *nums,int start,int end,int key)
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

int findPos(int *arr,int key)
{
    int l=0,h=1;
    int val=arr[h];
    while(val<key)
    {
        l=h;
        h*=2;
        val=arr[h];
    }
    return binarySearch(arr,l,h,key);
}
int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,
                               140, 160, 170};
    int ans = findPos(arr, 10);
    if (ans==-1)
        cout << "Element not found";
    else
        cout << "Element found at index :" << ans;//4

    return 0;
}
