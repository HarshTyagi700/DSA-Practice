/*
https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1#

Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Example 1:

Input: str1 = "heap", str2 = "pea"
Output: 3
Explanation: 2 deletions and 1 insertion
p and h deleted from heap. Then, p is 
inserted at the beginning One thing to 
note, though p was required yet it was 
removed/deleted first from its position 
and then it is inserted to some other 
position. Thus, p contributes one to the 
deletion_count and one to the 
insertion_count.
Example 2:

Input : str1 = "geeksforgeeks"
str2 = "geeks"
Output: 8
Explanation: 8 insertions
*/
int minOperations(string str1, string str2) 
	{ 
	    int n=str2.size();
	    int m=str1.size();
	    int t[m+1][n+1];
	    for(int i=0;i<=str1.size();i++)
	    for(int j=0;j<=str2.size();j++)
	    {
	        if(i==0||j==0)
	            t[i][j]=0;
	        else 
	        t[i][j]=(str1[i-1]==str2[j-1]) ? (1+ t[i-1][j-1]):(max(t[i-1][j],t[i][j-1]));	  
    	}
    // 	 for(int i=0;i<=str1.size();i++)
    // 	 {
	   // for(int j=0;j<=str2.size();j++)
	   // {cout<<t[i][j]<<" ";
	        
	   // }
    // 	 cout<<'\n';}
	   return str1.size()+str2.size()-2*t[str1.size()][str2.size()];
	    
	    
	} 
