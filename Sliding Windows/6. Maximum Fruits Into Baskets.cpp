//https://leetcode.com/problems/fruit-into-baskets/
/*
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

 

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
*/
int totalFruit(vector<int>& fruits) {
    /*
    Two pointer approach we'll starting putting elements into
    map from 0th idx
    We'll have map that will be storing count of fruits[i]
    The time when map.size() becomes greater than 2
    We'll start incrementing ith pointer till the time the 
    map.size() is not less than or equal to 2 (or is greater than 2)
    Again at that time we'll check for maxAnswer and will proceed with j pointer  
    */
        int maxFruits=1;
        unordered_map<int,int> mp;//fruits[i]->count
        int j=0,i=0,n=fruits.size();
        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()<=2){
                maxFruits=max(maxFruits,j-i+1);
                j++;
            }
      
            else{
                while(i<n and mp.size()>2){
                    mp[fruits[i]]--;
                    //reducing size if the type of fruits becomes
                    //zero
                    if(mp[fruits[i]]==0) mp.erase(fruits[i]);
                    i++;
                }
                if(mp.size()==2)
                maxFruits=max(maxFruits,j-i+1);
                j++;
            }
        }
        return maxFruits;
    }