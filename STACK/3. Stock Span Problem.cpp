//https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1/#

/*
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stocks price for all n days. 
The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Example 1:

Input: 
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
Explanation:
Traversing the given input span for 100 
will be 1, 80 is smaller than 100 so the 
span is 1, 60 is smaller than 80 so the 
span is 1, 70 is greater than 60 so the 
span is 2 and so on. Hence the output will 
be 1 1 1 2 1 4 6.
Example 2:

Input: 
N = 6, price[] = [10 4 5 90 120 80]
Output:
1 1 2 4 5 1
Explanation:
Traversing the given input span for 10 
will be 1, 4 is smaller than 10 so the 
span will be 1, 5 is greater than 4 so 
the span will be 2 and so on. Hence, the 
output will be 1 1 2 4 5 1.
User Task:
The task is to complete the function calculateSpan() which takes two parameters, an array price[] denoting the price of stocks, and an integer N denoting the size of the array and number of days. This function finds the span of stock's price for all N days and returns an array of length N denoting the span for the i-th day.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

*/

//Same as Previous Greater to right
//We'll store indexes of previous greater to left
vector <int> calculateSpan(int price[], int n)
    {
       stack<pair<int,int>> st;//{Element,idx}
       vector<int> span(n);
       for(int i=0;i<=n-1;i++)
       {
           if(st.empty()){
               span[i]=i+1;//
           }
           else{
               while(!st.empty() and st.top().first<=price[i])
               st.pop();
               
               if(st.empty())
               span[i]=i+1;
               
               else span[i]=i-st.top().second;
           }
           st.push({price[i],i});
         }
        return span;
    }