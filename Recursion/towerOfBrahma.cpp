#include <iostream>
using namespace std;

void towerofBrahma(int n,string Source ,string Destination,string Helper)
{
    if(n==1)
    {
        cout<<"Move "<<n<<" Disk From "<<Source<<" To "<<Destination<<'\n';
        return;
    }
    towerofBrahma(n-1,Source,Helper,Destination);
    cout<<"Move "<<n<<" Disk From "<<Source<<" To "<<Destination<<'\n';
    towerofBrahma(n-1,Helper,Destination,Source);
}


int main()
{
    towerofBrahma(3,"A","C","B");

    return 0;
}

