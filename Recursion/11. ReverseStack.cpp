#include <iostream>
#include<stack>
using namespace std;

void addTemp(stack<char> &s,char temp)
{
    if(s.size()==0)
    {
        s.push(temp);
        return;
    }
    
    char temp1=s.top();
    s.pop();
    addTemp(s,temp);
    
    s.push(temp1);
    return;
    
}

void reverseStack(stack<char> &s)
{                                       // 5 < 3(0) < 2 < 1< 0(3)
    if(s.size()<=1)
    return;
    
    char temp=s.top();
    s.pop();
    reverseStack(s);
    
    addTemp(s,temp);
}

void printStack(stack<char> &s)
{
    if(s.size()==0)
    return;
    
    char temp=s.top();
    s.pop();
    printStack(s);
    
    cout<<temp<<" ";
    
    s.push(temp);
}

int main()
{
    stack<char> s;
    s.push('H');
    s.push('A');
    s.push('R');
    s.push('S');
    s.push('H');
    
    reverseStack(s);
    
    printStack(s);
    return 0;
}


