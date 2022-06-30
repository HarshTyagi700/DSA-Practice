/*
https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1#

Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

 

Example 1:

Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates 
to true in 4 ways ((T|T)&(F^T)), 
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
Example 2:

Input: N = 5
S = T^F|F
Output: 2
Explaination: ((T^F)|F) and (T^(F|F)) are the 
only ways.
 

Your Task:
You do not need to read input or print anything. Your task is to complete the function countWays() which takes N and S as input parameters and returns number of possible ways modulo 1003.

 

Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(N2)

 

Constraints:
1 ≤ N ≤ 200 

*/

 unordered_map<string,int> mp;
    int noOfWays(string S,int i,int j , bool isTrue)
    {
        if(i>j)
        return 0;
        if(i==j)
        {
            if(isTrue)
            return S[i]=='T'?1:0;
            else return S[i]=='F'?1:0;
        }
         string temp=to_string(i)+' '+to_string(j)+' '+to_string(isTrue);
        if(mp.find(temp)!=mp.end())
        return mp[temp];
        int ans=0;
        for(int k=i+1;k<=j-1;k+=2)
        {
            int LT=noOfWays(S,i,k-1,true);
            int RT=noOfWays(S,k+1,j,true);
            int LF=noOfWays(S,i,k-1,false);
            int RF=noOfWays(S,k+1,j,false);
            
            if(S[k]=='&')
            {
                if(isTrue)
                ans+=(LT*RT)%1003;
                else ans+=(LT*RF+LF*RT+LF*RF)%1003;
            }
            else  if(S[k]=='|')
            {
                if(isTrue)
                ans+=(LT*RT+LT*RF+LF*RT)%1003;
                else ans+=(LF*RF)%1003;
            }
            else
            {
                 if(isTrue)
                ans+=(LT*RF+LF*RT)%1003;
                else ans+=(LF*RF+LT*RT)%1003;
            }
                
        }
        return mp[temp]=ans%1003;
        
    }
    int countWays(int N, string S){
        mp.clear();
       return noOfWays(S,0,S.size()-1,true);
    }

//Memoization 
#define ll long long int
#define M 1000000007

ll solve(string &exp,int i,int j,int res,vector<vector<vector<ll>>> &dp)
{
    if(i>j)
        return 0;
    if(i==j)
    {
        if(res==1)
            return dp[i][j][res]=(exp[i]=='T'?1:0);
        else return dp[i][j][res]=(exp[i]=='F'?1:0);        
    }
    
    if(dp[i][j][res]!=-1)
        return dp[i][j][res];
    
    ll ways=0;
    for(int k=i+1;k<=j-1;k+=2)
    {
        ll LT=solve(exp,i,k-1,1,dp)%M;
        ll RT=solve(exp,k+1,j,1,dp)%M;
        ll LF=solve(exp,i,k-1,0,dp)%M;
        ll RF=solve(exp,k+1,j,0,dp)%M;
        switch(exp[k])
        {
            case '&':
                {
                    if(res)
                       ways+=((RT*LT)%M);
                    else ways+=((LF*RF)%M+(LT*RF)%M+(LF*RT)%M);
                };break;
                
            case '^':{
             if(res)
                 ways+=((LT*RF)%M+(LF*RT)%M);
             else ways+=((LT*RT)%M+(LF*RF)%M);
            };break;
            case '|':{
                if(res)
                    ways+=((LT*RT)%M+(LT*RF)%M+(LF*RT)%M);
                else ways+=((LF*RF)%M);
            };break;      
        }     
    } 
    return dp[i][j][res]=(ways%M);
}
int evaluateExp(string & exp) {
    int n=exp.length();
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)) );
    return (int)(solve(exp,0,n-1,1,dp)%M);
}