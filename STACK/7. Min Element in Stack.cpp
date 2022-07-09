//https://leetcode.com/problems/min-stack/
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/


/*
Approach 1-> Extra space O(N)
we can have another monotonic stack ss and we'll keep the min element at the top 
and will pop it whenever s.top()==ss.top()
*/
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> ss;
    MinStack() {
        
    }
    
    void push(int val) {
        	s.push(val);
	if(ss.size()==0||ss.top()>=val)//pushing if we have got a new min element
	ss.push(val);
    }
    
    void pop() {
        int popEle=s.top();
	s.pop();
	if(popEle==ss.top())//checking while popping if it was the minimum
	ss.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        if(ss.size()==0)
	return -1;
	return ss.top();
    }
};

//Another approach keep space constant 
//we'll have a minElemennt variable and will store a modified value for newMin in the stack
//and while popping or returning top will check if that value is less than min that means 
//it's actual value is min
//
class MinStack {
public:
    stack<long long> st;
    long long minEle;
    MinStack() {
        while(!st.empty()) st.pop();
        minEle=INT_MAX;
    }
    
    void push(int value) {
        long long val=value;
        if(st.empty()){
            minEle=val;
            st.push(val);
        }
        else{
            if(val<minEle)//new min found
            {
                //will stored modified less value than min
                //val<minEle
                //val-minEle<0
                //2*val-minEle<val
                st.push(2*val-minEle);
                minEle=val;
            }
            else st.push(val);
        }
    }
    
    void pop() {

        long long temp=st.top();
        st.pop();
        if(temp<minEle)//will calculate newMin that was previous min
        {
            minEle=2*minEle-temp;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        
         long long temp=st.top();
        if(temp<minEle)
            return minEle;
        return temp;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return minEle;
    }
};