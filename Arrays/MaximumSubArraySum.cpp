#include <iostream>
#define INT_MAX -2147483647
using namespace std;
    int maxSubArraySum(int Arr[],int N )
    {
        int maxSoFar=INT_MAX;
        int maxTillHere=0;
        for(int i=0;i<N;i++)
        {
            maxTillHere+=Arr[i];
            if(maxSoFar<maxTillHere)
                maxSoFar=maxTillHere;
            if(maxTillHere<0)
                maxTillHere=0;
        }
        return maxSoFar;
    }

int main()
{
    
    int n,m;
    cin>>n>>m;
    int Arr[n];
    for(int i=0;i<n;i++)
    cin>>Arr[i];
    int k,x;
    while(m--)
    {
        cin>>k>>x;
        Arr[k-1]=x;
        cout<<maxSubArraySum(Arr,n);
    }
    return 0;
}

