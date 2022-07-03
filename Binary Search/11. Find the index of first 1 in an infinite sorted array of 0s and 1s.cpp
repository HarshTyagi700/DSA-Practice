
#include <iostream>

using namespace std;

int indexOfFirst1(int *arr)
{
    int m,l=0,h=1,index=-1;
    int highNum=arr[1];
    while(highNum<1)
    {
        l=h;
        h*=2;
        highNum=arr[h];
    }
    while(l<=h)
    {   m=l+(h-l)/2;
        if(arr[m]==1)
        {
            index=m;
            h=m-1;
        }
        else l=m+1;
    }
    return index;
    
}

int main()
{
    int nums[] = { 0, 0, 1, 1, 1, 1 };
    
    cout<<indexOfFirst1(nums);//2

    return 0;
}
