 //Recursive Function to return max value that can be put in knapsack of capacity W.
    int knapSackRecursive(int W, int wt[], int val[], int n)
    {
        if(W==0||n==0)
        return 0;
        if(wt[n-1]<=W)
        {
            return max(val[n-1]+knapSackRecursive(W-wt[n-1],wt,val,n-1),
                        knapSackRecursive(W,wt,val,n-1));
        }
        else return knapSackRecursive(W,wt,val,n-1);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int t[n+1][W+1];
     for (int i=0;i<n+1;i++)
     {
        for(int j=0;j<W+1;j++)
        {
          if(i==0||j==0)
            t[i][j]=0;
        else if(wt[i-1]<=j)
        {
          t[i][j]=max( val[i-1] + t[i-1][j-wt[i-1]] , t[i-1][j]  );
         }
        else 
        t[i][j]= t[i-1][j];
      }
     }
    return t[n][W];
    }
