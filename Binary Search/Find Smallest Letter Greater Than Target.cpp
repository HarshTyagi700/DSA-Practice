/* 
Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.

Note that the letters wrap around.

For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.
 

Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Example 3:

Input: letters = ["c","f","j"], target = "d"
Output: "f"
Example 4:

Input: letters = ["c","f","j"], target = "g"
Output: "j"
Example 5:

Input: letters = ["c","f","j"], target = "j"
Output: "c"

https://leetcode.com/problems/find-smallest-letter-greater-than-target/
*/
char nextGreatestLetter(vector<char>& letters, char target) {
        char ans=letters[0];
        int n=letters.size();
        if(target>=letters[n-1]||target<letters[0])
            return ans;
        int start=0,end=n-1,mid;
        ans='z'+ 1;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(letters[mid]==target)
                start=mid+1;
            else if(letters[mid] < ans && letters[mid] > target)
            {
                ans = letters[mid];
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
