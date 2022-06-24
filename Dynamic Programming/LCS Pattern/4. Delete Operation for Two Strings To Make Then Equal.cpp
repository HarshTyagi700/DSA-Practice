/*
https://leetcode.com/problems/delete-operation-for-two-strings/
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
 

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.
*/
int minDistance(string word1, string word2) {
          int t[word1.size()+1][word2.size()+1];
        for(int i=0;i<=word1.size();i++)
            t[i][0]=0;
        for(int j=1;j<=word2.size();j++)
            t[0][j]=0;
        
        for(int i=1;i<=word1.size();i++)
            for(int j=1;j<=word2.size();j++)
            { 
                if(word1[i-1]==word2[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        return word1.size()+word2.size()-2*t[word1.size()][word2.size()];
    }

//More Optimised Code will be taking only O(min(L1,L2)) - > Space Complexity And O(L1*L2) -> Time Complexity
int minDistance(string& word1, string& word2) {        
    if(size(word1) < size(word2)) swap(word1, word2);
	vector<vector<int> >dp(2, vector<int>(size(word2) + 1));
	for(int i = 0; i <= size(word1); i++) 
		for(int j = 0; j <= size(word2); j++) 
			if(!i || !j) dp[i & 1][j] = i + j;
			else dp[i & 1][j] = word1[i - 1] == word2[j - 1] ? dp[(i - 1) & 1][j - 1] : 1 + min(dp[(i - 1) & 1][j], dp[i & 1][j - 1]);
	return dp[size(word1) & 1][size(word2)];
}
