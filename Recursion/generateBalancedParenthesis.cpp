//https://leetcode.com/problems/generate-parentheses/submissions/
#include<bits/stdc++.h>
using namespace std;
 void solve(int openBracket,int closeBracket, string out, vector<string> &ans)
    {
        if(openBracket==0&&closeBracket==0)
        {
            ans.push_back(out);
            return;
        }
        if(openBracket!=0)
            solve(openBracket-1,closeBracket,out+'(',ans);
        if(closeBracket>openBracket) 
            solve(openBracket,closeBracket-1,out+')',ans);
        
    }
    
    vector<string> generateParenthesis(int n) {
        int openBracket,closeBracket;
        openBracket=closeBracket=n;
        vector<string> ans;
        string out="";
        out.push_back('(');
        openBracket--;
        solve(openBracket,closeBracket,out,ans);
        return ans;
    }
int main()
{
    vector<string> ans;
    int n=3;
    ans=generateParenthesis(n);
    for(int p=0;p<ans.size();p++)
    cout<<ans[p]<<"\n";
    return 0;
}

