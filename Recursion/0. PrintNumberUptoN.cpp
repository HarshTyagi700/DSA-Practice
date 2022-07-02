#include <iostream>
#include<string.h>
using namespace std;

int i=1;//i=3
void printAllNum(int N)
{
    if(N>=1)//5>=1
    {
    cout<<i<<" ";//1
    i++;
    printAllNum(--N);//N-- -> 5(4)
    }
}
string printNum(int N)
{
    if(N==1)
    {
    cout<<1<<"\n";
    string base="1 ";
    return base;
    }
    string subStr=printNum(N-1);//printNum(3-1)
    subStr+=to_string(N);
    subStr.append(" ");
     cout<<subStr<<"\n";
     return subStr;
}

int main()
{
    int  N;
    cin>>N;
    printNum(N);// 1 2 3 4 5 6 . . ..N  // 5 4 3 2 1
    return 0;
}
/* 
1
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5
For printing pattern
*/

