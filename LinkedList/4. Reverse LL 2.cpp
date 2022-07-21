//https://leetcode.com/problems/reverse-linked-list-ii/
/*
92. Reverse Linked List II
Medium

6737

313

Add to List

Share
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?
*/

class Solution {
private:
    ListNode* reverseList(ListNode *head){
        if(!head || !head->next)
            return head;
        ListNode *reverseHead=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return reverseHead;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //we'll start from first node and check for left
        //and right node. After that we'll trim that in-between
        //list and reverse it and then join it with rest of 
        // the list
       int count=1;
        ListNode *prevNode=NULL,*currNode=head;
        while(count!=left){
            prevNode=currNode;
            currNode=currNode->next;
            count++;
        }
        ListNode* revStart=currNode;
        while(count!=right){
            currNode=currNode->next;
            count++;
        }
        ListNode * restList=currNode->next;
        currNode->next=NULL;
        ListNode *reverseHead=reverseList(revStart);
        count=left;
        currNode=reverseHead;
        while(count!=right)
        {
            currNode=currNode->next;
            count++;
        }
        currNode->next=restList;
        
        if(prevNode) prevNode->next=reverseHead;
        return prevNode?head:reverseHead;
    }
};