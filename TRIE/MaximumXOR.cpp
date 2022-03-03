//https://www.codingninjas.com/codestudio/problems/maximum-xor_973113
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
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    // Write your code here.   
    Trie T1;
    int maxi=0;
    for(int i=0;i<n;i++)
        T1.insert(arr1[i]);
    for(int i=0;i<m;i++)
        maxi=max(T1.getMax(arr2[i]),maxi);
    return maxi;
    
}
