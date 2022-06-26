/*
https://leetcode.com/problems/reverse-linked-list/

Given the head of a singly linked list, reverse the list, and return the reversed list.
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/

//Recursive Solution
 ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
         ListNode* reverseHead=reverseList((head->next));
        head->next->next=head;
        head->next=nullptr;
        return reverseHead;
        
    }

    //Iterative Solution
     ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
         ListNode *next,*curr=head,*prev=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        
        
    }