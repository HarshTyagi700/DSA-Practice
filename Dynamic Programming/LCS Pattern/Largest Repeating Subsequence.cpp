/*

https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#

Given a string str, find the length of the longest repeating subsequence such that it can be found twice in the given string. The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B.

Example 1:

Input:
str = "axxxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x x y 
0 1 2 3 4

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 


subsequence B
x x
0 1  <-- index of subsequence B
------
2 3  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.
Example 2:

Input:
str = "aab"
Output: 1
Explanation: 
The longest reapting subsequenece is "a".

Your Task:
You don't need to read or print anything. Your task is to complete the LongestRepeatingSubsequence() which takes str as input parameter and returns the length of the longest repeating subsequnece.


Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)


Constraints:
1 <= |str| <= 103
*/
//Find LCS of same string keeping in mind that same character should never be taken from the same index(i!=j)
int LongestRepeatingSubsequence(string str){
		  //  string revStr=string(str.rbegin(),str.rend());
		    int T[2][str.size()+1];
		    for(int i=0;i<=str.size();i++)
		    for(int j=0;j<=str.size();j++)
		    {
		        if(!i||!j)
		        T[i&1][j]=0;
		        else if(str[i-1]==str[j-1]&&(i!=j))
		        T[i&1][j]=T[(i-1)&1][j-1]+1;
		        else T[i&1][j]=max(T[(i-1)&1][j],T[i&1][j-1]);
		    }
		    return T[str.size()&1][str.size()];
		}
