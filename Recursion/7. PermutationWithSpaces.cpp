#include <bits/stdc++.h>

using namespace std;

bool myComp(string s1,string s2)
{
    return (s1.size()<s2.size());
}

 void solve(string S,string out,vector<string> &ans)
    {
        if(S.length()==0)
        {
            ans.push_back(out);
            return;
        }
        char temp=S[0];
        out.push_back(S[0]);
        S.erase(S.begin()+0);
        solve(S,out,ans);
        out.erase(out.end()-1);
        out.push_back(' ');
        out.push_back(temp);
        solve(S,out,ans);
    }
    vector<string> permutation(string S){
        string out;
        vector<string> ans;
        out.push_back(S[0]);
        S.erase(S.begin()+0);
        solve(S,out,ans);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
int main()
{   
    vector<string> ans;
    string str="ABCD";
    
    ans=permutation(str);
    for(int p=0;p<ans.size();p++)
    cout<<ans[p]<<"\n";

    return 0;
}


