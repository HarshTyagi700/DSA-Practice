//https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
/*
Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.
Your Task:
Complete the function search() which takes two strings pat, txt, as input parameters and returns an integer denoting the answer. You don't to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(26) or O(256)

Constraints:
1 <= |pat| <= |txt| <= 105
Both string contains lowercase english letters.
*/
	int search(string pat, string txt) {
        //map will be used to count the occurence of each char
        //will decrement count wheneven any char's occurence becomes zero
	    unordered_map<char,int> mp;
	    int anaCount=0;
	    int count,k=pat.length();
	    for(int i=0;i<k;i++)
	    mp[pat[i]]++;
	    //the size of this count should be zero if all chars among window k
	    //matches with pat
	    count=mp.size();
	    int j=0,i=0,n=txt.length();
	    while(j<n){
	        if(mp.find(txt[j])!=mp.end()){
	            mp[txt[j]]--;
	            if(mp[txt[j]]==0)
	            count--;
	        }
	        if(j-i+1<k) j++;
	        else {
	            if(count==0)
	            anaCount++;
	            if(mp.find(txt[i])!=mp.end())
	            {
	                mp[txt[i]]++;
	                if(mp[txt[i]]==1) count++;//checking if it's count becomes 1
	            }
	            i++,j++;
	        }
	    }
	    return anaCount;
	    
	}