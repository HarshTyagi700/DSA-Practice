#include<iostream>
#include<string.h>

using namespace std;

void printSubset(string inp,string out)
{
    if(inp.length()==0)
        {
            cout<<"val"<<out<<"\n";
            return;
        }
    string out2;
    out2=out;
    out2.push_back(inp[0]);
    inp.erase(inp.begin());
    printSubset(inp,out);
    printSubset(inp,out2);
}

int main()
{
    string str1="abc",str2="";
    printSubset(str1,str2);
}
