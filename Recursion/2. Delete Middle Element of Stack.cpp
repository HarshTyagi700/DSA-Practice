//https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1/
/*
Given a stack with push(), pop(), empty() operations, delete the middle of the stack without using any additional data structure.
Middle: ceil((size_of_stack+1)/2) (1-based index)
 

Example 1:

Input: 
Stack = {1, 2, 3, 4, 5}
Output:
ModifiedStack = {1, 2, 4, 5}
Explanation:
As the number of elements is 5 , 
hence the middle element will be the 3rd
element which is deleted
Example 2:

Input: 
Stack = {1 2 3 4}
Output:
ModifiedStack = {1 3 4}
Explanation:
As the number of elements is 4 , 
hence the middle element will be the 2nd
element which is deleted
*/

//Recursive Solution
class Solution
{
    private:
    void solve(stack<int> &s,int k)
    {
        if(k==1)
        {
            s.pop();
            return;
        }
        //if k!=1 that means it is not the middle element
        //pop out the top element
        //then call the function for reduced value of k
        int temp=s.top();
        s.pop();
        solve(s,k-1);
        //after this we'll again push the element that was popped out
        s.push(temp);
    }
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
       if(s.size()==0)
       return ;
       int k=s.size()/2+1;//taking middle element position
       solve(s,k);
       
    }
};