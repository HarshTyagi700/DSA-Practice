//when a[i]>=0
int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int maxLen=0;
        int j=0,i=0,sum=0;
        while(j<N)
        {
            sum+=A[j];
            if(sum<K) j++;
            else if(sum==K) {
                maxLen=max(maxLen,j-i+1);
                j++;
                //there can be more nums which will cancel out each other 
                //like -2 2 -4 3 1 == 0
                //so they will compute in having larger array
            }
            else if(sum>K)
            {
                while( sum>K and i<N )
                {
                    sum-=A[i];
                    i++;
                //considering the case when first the sum was less than l
                //then we might have taken more elements from right side
                //that exceeds k
                //so there might be a possiblity that we would get a answer
                //if we leave elements from left side
                if(sum==K)
                maxLen=max(maxLen,j-i+1);
                //there can be multiple such values so taking the largest one
                }
                
                j++;
            }
        }
        return maxLen;
    } 



    //when  -100000<a[i]<100000

    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int ,int> mp;//key-> sum value->idx
        int sum=0;
        mp[0]=-1;
        int maxLen=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
            if(mp.find(sum-K)!=mp.end()){//this can be answer
                maxLen=max(maxLen,i-mp[sum-K]);
            }
            //longest answer will be the first idx where we get 
            //sum
            if(mp.find(sum)==mp.end())
            mp[sum]=i;            
        }
        return maxLen;
    } 