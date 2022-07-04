//same as previous just check function is different 
bool canEat(vector<int>& piles, int h,int k)
    {
        int count=0;
        for(int it:piles)
        {
            count+=(it/k);
            if(it%k!=0)
                count++;//taking upper bound
            if(count>h)
                return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=0;
        for(auto it:piles)
            high=max(high,it);
        int low=1;
        int mid,k;
        int ans;
         while(low<=high)
         {
             k=low+((high-low)>>1);
             if(canEat(piles,h,k))
             {
                 ans=k;
                 high=k-1;
             }
             else low=k+1;
         }
        return ans;
    }