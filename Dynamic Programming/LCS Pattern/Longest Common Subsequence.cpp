//https://leetcode.com/problems/longest-common-subsequence/

int longestCommonSubsequence(string text1, string text2) {
        int T[text1.length()+1][text2.length()+1];
        for(int i=0;i<=text1.length();i++)
            T[i][0]=0;
        for(int j=1;j<=text2.length();j++)
            T[0][j]=0;
        for(int i=1;i<=text1.length();i++)
            for(int j=1;j<=text2.length();j++)
            {
                if(text1[i-1]==text2[j-1])//if matches then we will add +1 to ans excluding this two chars 
                    T[i][j]=1+T[i-1][j-1];
                //if doesn't match then we will take max that we will get after including one char extra from any one text
                else T[i][j]=max(T[i][j-1],T[i-1][j]);
                
            }
        return T[text1.length()][text2.length()];
    }
