#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<vector<long long int>> t(5,vector<long long int> (3,-1) );
    cout<<"Number of Rows:"<<t.size()<<'\n';
    cout<<"Number of Columns:"<<t[0].size()<<'\n';
    int count=0;
    for(int i=0;i<t.size();i++)
    {
    for (int j = 0; j < t[0].size(); j++) {
        /* code */
        t[i][j]=count++;
        cout<<t[i][j]<<" ";
    }
    cout<<'\n';
        
    }
    
    cout<<"Hello World";

    return 0;
}

