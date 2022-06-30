/*
https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1#

Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
Example 2:

Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".

Your Task:
You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as input parameter and returns minimum number of partitions required.


Expected Time Complexity: O(n*n) [n is the length of the string str]
Expected Auxiliary Space: O(n*n)


Constraints:
1 ≤ length of str ≤ 500
*/
class Solution{
public:
    int t[502][502];
    bool isPalindrome(string str,int i,int j)
    {
        if(i>=j)
        return true;
        while(i<j)
        {
            if(str[i]!=str[j])
            return false;
            i++,j--;
        }
        return true;
    }
    
    int noOfPartitions(string str,int i,int j)
    {
        if(i>=j)
        return 0;
        if(t[i][j]!=-1)
        return t[i][j];
        if(isPalindrome(str,i,j)==true)
            return t[i][j]=0;
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            /*Here we have optimised the for loop as we can also check whether t[i][k]
            and t[k+1][j] values are already present or not .If they are then we will simply return 
            the corresponding value from the table otherwise we have to call the function 
            noOfPartitions for that indexes.
            */
            int temp,left,right;
            if(t[i][k]!=-1)
            left=t[i][k];
            else left=noOfPartitions(str,i,k);
            
            if(t[k+1][j]!=-1)
            right=t[k+1][j];
            else right=noOfPartitions(str,k+1,j);
            
            temp=left+1+right;
            if(temp<ans)
            ans=temp;
        }
        return t[i][j]=ans;
        
            
    }
    
    int palindromicPartition(string str)
    {
        memset(t,-1,sizeof t);
        return noOfPartitions(str,0,str.size()-1);
    }
};

//bottom-up dp (Tabulation)
class Solution {
private:
    bool isPalindrome(string s,int i,int j)
    { 
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }

    int solve(string s,int i,vector<int> &dp)
    {
        int n=s.length();
        if(i==n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];

        int tempAns,minCost=INT_MAX;
        for(int k=i;k<n;k++)
        {

            if(isPalindrome(s,i,k))
            {
                tempAns=1+solve(s,k+1,dp);
                minCost=min(minCost,tempAns);
            }
            
        }
        return dp[i]=minCost;
    }
public:
    int minCut(string s) {
        //I'll try to do front partition and check whether the 
        //first partition is palindrome , if it is then only I'll 
        // check for the left string i.e. calling function recursively
       
        int n=s.length();
         if(isPalindrome(s,0,n-1))
        return 0;
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {  
            int tempAns,minCost=INT_MAX;
           for(int k=i;k<n;k++)
        {

            if(isPalindrome(s,i,k))
            {
                tempAns=1+dp[k+1];
                minCost=min(minCost,tempAns);
            }
           
        } 
                        
        dp[i]=minCost;
         
        }
        return dp[0]-1;
    }
};