#include<bits/stdc++.h>
using namespace std;

void solve(int N,string out,vector<string> &ans,int one,int zero)
{
    if(N==0)
    {
        ans.push_back(out);
        return;
    }
    if(one>zero)
        solve(N-1,out+'0',ans,one,zero+1);
    
    solve(N-1,out+'1',ans,one+1,zero);
}

vector<string> printNBit(int N)
{
    vector<string> ans;
    string out;
    int one ,zero=0;
    out.push_back('1');
    N--;
    one++;
    solve(N,out,ans,one,zero);
    return ans;
}

int main()
{
    int N=2;
    vector<string> ans;
    ans=printNBit(N);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<'\n';
    return 0;
    
}
