#include<bits/stdc++.h>
using namespace std;

// vector<int> searchRange(vector<int>& nums, int target) {
//         if(nums.size()==1)
//         {
//             if(nums[0]==target)
//                 return vector<int>{0,0};
//             else return vector<int>{-1,-1};
//         }
//         int start=0 ,end=nums.size()-1;
//         int mid=start+(end-start)/2;
//         int index=-1;
//         while(start<=end)
//         {
//             mid=start+(end-start)/2;
//             if(nums[mid]==target)
//             {
//                 index=mid;
//                 break;
//             }
//             if(nums[mid]<target)
//                 start=mid+1;
//             else end=mid-1;       
//         }
//         if(index==-1)
//           return vector<int>{-1,-1};
//         else{
//             start=end=index;
//             while(nums[++index]==target)
//                     end++;
                    
//             index=start;
//             while(nums[--index]==target)
//                 start--;
//             return vector<int>{start,end};
//         }
//     }
    
    
vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==1)
        {
            if(nums[0]==target)
                return vector<int>{0,0};
            else return vector<int>{-1,-1};
        }
        int start=0 ,end=nums.size()-1;
        int mid;
        int index=-1,first=-1,last=-1;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                first=mid;
                end=mid-1;
            }
            else if(nums[mid]<target)
                start=mid+1;
            else end=mid-1;       
        }
        start=0 ;
        end=nums.size()-1;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                last=mid;
                start=mid+1;
            }
            else if(nums[mid]<target)
                start=mid+1;
            else end=mid-1;       
        }
//         if(index==-1)
//            return vector<int>{-1,-1};
//         else{
//             start=end=index;
//             while(nums[++index]==target)
//                     end++;
                    
//             index=start;
//             while(nums[--index]==target)
//                 start--;
            return vector<int>{first,last};
    
    }
int main()
{
    vector<int> nums={2,2};
    vector<int> ans=searchRange(nums,2);
    cout<<ans[0]<<':'<<ans[1];

    return 0;
}


