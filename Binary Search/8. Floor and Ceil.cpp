
#include <bits/stdc++.h>

using namespace std;


int findFloor(long long int arr[], int N, long long int K) {
    long long int mid,start=0,end=N-1;
    long long int ans=-1,index=-1;
    while(start<=end)
    {
        mid=start+(end-start)/2;
       if(arr[mid]==K)
        return mid;
        if(arr[mid]<K)
        {
            ans=arr[mid];//this can be my answer
            index=mid;
            start=mid+1;
        }
        else end=mid-1;
    }
    if(index==-1)
    return -1;
    else 
    return arr[index];
}
int findCeil(long long int arr[], int N, long long int K) {
    long long int mid,start=0,end=N-1;
    long long int ans=INT_MAX,index=-1;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(arr[mid]==K)
        return arr[mid];
        if(arr[mid]>K)
        {
            ans=arr[mid];
            index=mid;
            end=mid-1;
        }
        else start=mid+1;
    }
    if(index==-1)
    return -1;
    else 
    return ans;
}
int main()
{
    long long int arr[]={66,67,68,69,70,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130};
    cout<<findCeil(arr,64,131)<<'\n';//-1
    cout<<findCeil(arr,64,71)<<'\n';//72
    cout<<findFloor(arr,64,65)<<'\n';//-1
    cout<<findFloor(arr,64,71)<<'\n';//70
    return 0;
}


