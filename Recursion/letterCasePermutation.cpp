//https://leetcode.com/problems/letter-case-permutation/
#include <iostream>

using namespace std;

void solve(string s,string out,vector<string> &ans)
    {
        if(s.empty())
        {
            ans.push_back(out);
            return;
        }
        if(!isalpha(s[0]))
        {
            out.push_back(s[0]);
            s.erase(s.begin()+0);
            solve(s,out,ans);
            return;
        }
        string upper;
        upper=out;
        upper.push_back(toupper(s[0]));
        out.push_back(tolower(s[0]));
        s.erase(s.begin()+0);
        solve(s,out,ans);
        solve(s,upper,ans);
            
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string out;
        solve(s,out,ans);
        return ans;
    }

int main()
{
    cout<<"Hello World";

    return 0;
}

