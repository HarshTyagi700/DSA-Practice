#include <iostream>
using namespace std;

int fact(int N)
{
    if(N==1||N==0)
    {
        return 1;//Base Case
    }
    int num=N*fact(N-1);//Hypothesis 
    return num;//Induction 
}
int main()
{
    int N;
    cin>>N;
    cout<<fact(N);//5 ~ 120
    return 0;
}

