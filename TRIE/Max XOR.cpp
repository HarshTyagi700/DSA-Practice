//1707. Maximum XOR With an Element From Array
//https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
struct Node{
  Node *links[2];
  bool containsKey(int bit){
      return (links[bit]!=NULL);
  }
  void put(int bit,Node * node){
      links[bit]=node;
  }
  Node * get(int bit){
     return links[bit];
 }
};
class Trie{
    private: Node *root;
    
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node *node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(!node->containsKey(bit))
                node->put(bit,new Node());//Allocating memory and passing its address
            node=node->get(bit);
        }
    }
    int getMax(int num){
        Node * node=root;
        int maxAns=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit))
            {
                node=node->get(1-bit);
                maxAns=(1<<i)|maxAns;
            }
            else{
                node=node->get(bit);
            } 
        }
        return maxAns;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int q=queries.size();
        Trie T;
      //We'll put the queries in ascending order of Mi and calculate the ans 
      //and will store it at the described index of queries
      //so we need this type of vector.
        vector< pair<int, pair<int,int> > > offQ;
      //storing Mi first bcz we need to sort acc. to that
        for(int i=0;i<q;i++)
            offQ.push_back({queries[i][1],{queries[i][0],i}});
        sort(offQ.begin(),offQ.end());
      //sorting nums also so that we get elements in order 
        sort(nums.begin(),nums.end());
        vector<int> maxXor(q,0);
        int ind=0;
        int n=nums.size();
        for(int i=0;i<q;i++){
          //fetching values from offline Queries
            int xi=offQ[i].second.first;
            int mi=offQ[i].first;
            int qInd=offQ[i].second.second;
            while(ind<n && nums[ind]<= mi)
            {
                T.insert(nums[ind++]);
            }
          //This means no element was less than Mi
            if(ind==0)
                maxXor[qInd]=-1;
            else
                maxXor[qInd]=T.getMax(xi);
        }
        return maxXor;
        
    }
};
