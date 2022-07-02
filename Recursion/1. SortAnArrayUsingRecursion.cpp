#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void mergeVec(vector<int> &v,int num)// 1,2,3,4  7
{ 
    if(v.size()==0||v[v.size()-1]<=num)
    {
        v.push_back(num);
        return ;
    }
    else 
    {
        int temp=v[v.size()-1];
        v.pop_back();
        mergeVec(v,num);
        v.push_back(temp);
        return ;
    }
    
}

void sortVec(vector<int> &v)
{
    if(v.size()==1||v.size()==0)
    return ;
    int num=v[v.size()-1];//storing last element from vector
    v.pop_back();//removing last element from vector
    sortVec(v);//calling function for vector size N-1.
    //Induction
    mergeVec(v,num);//merging that one element that were removed into the vector
}

int main()
{
    vector<int> vec={3,1,2};
  
    sortVec(vec);
    
    vector<int>::iterator ptr;
    for(ptr=vec.begin();ptr!=vec.end();ptr++)
    cout<<*ptr<<" ";
    

    return 0;
}

