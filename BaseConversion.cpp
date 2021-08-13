#include <iostream>
#include<string>
using namespace std;

string expansionBase(int n, int b)//n is the decimal no. and b is the base
{   string ans;
    int q=n;
    int c;
    while(q!=0)
    {
        c = q%b;
        q/=b;
        char s[2];
         if(c>9)
            c+=7;
        s[0]=(char)(c+'0'); 
       
        ans.insert(0,s);
        
    }
    return ans;
}


int main()
{
    int n ,b ;
    cout<<"Enter the decimal number:";
    cin>>n;
    cout<<"Enter the base number:";
    cin>>b;
    string out = expansionBase(n,b);
    cout<<"Value of : "<<n<<" for base : "<<b<<" is ->"<<out;
    return 0;
}


