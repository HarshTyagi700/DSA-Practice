
#include <iostream>

using namespace std;

int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int n=nums.size();
        int ans;
        int mid,start=0,end=n-1;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(nums[mid]!=nums[(mid+1)%n] && nums[mid]!=nums[(mid-1+n)%n])
            {
                ans=nums[mid];
                break;
            }
            if(mid%2==0)
            {
                if(nums[mid]==nums[mid+1])
                    start=mid+1;
                else end=mid-1;
            }
            else {
                if(nums[mid]==nums[mid-1])
                    start=mid+1;
                else end=mid-1;
            }
        }
        return ans;
    }
     //using Bitwise XOR operator
     int singleNonDuplicate(vector<int>& nums) {
        int xorResult=nums[0];
        for(int i=1;i<nums.size();i++)
            xorResult^=nums[i];
        return xorResult;
    }
int main()
{
    cout<<"Hello World";

    return 0;
}

