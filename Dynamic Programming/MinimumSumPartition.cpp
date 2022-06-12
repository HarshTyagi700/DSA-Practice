
//https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/#
int minDifference(int arr[], int n)  { 
	    int range=0;
	    for(int i=0;i<n;i++)
	    range+=arr[i];
	    bool T[n+1][range/2+1];
	    memset(T,sizeof(T),false);
	    for(int j=1;j<range/2+1;j++)
	    T[0][j]=false;
	    for(int i=0;i<n+1;i++)
	    T[i][0]=true;
	    for(int i=1;i<n+1;i++)
	    {
	        for(int j=1;j<range/2+1;j++)
	        {
	            if(arr[i-1]<=j)
	            T[i][j]=T[i-1][j] || T[i-1][j-arr[i-1]];
	            else T[i][j]=T[i-1][j] ;
	        }
	    }
	    int minDiff=INT_MAX;
	    for(int j=0;j<range/2+1;j++)
	    {
	       if(T[n][j])
	       minDiff=min(minDiff,range-2*j);
	    }
	   // for(int i=0;i<n+1;i++)
	   // {
	   //     for(int j=0;j<range/2+1;j++)
	   //     {
	   //         cout<<T[i][j]<<' ';
	   //     }
	   //     cout<<'\n';
	        
	   // }
	   // cout<<range<<'\n';
	    return minDiff;
	    
	} 
