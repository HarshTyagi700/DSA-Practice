//https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#
/*
A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124 
Your Task:
Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
*/
/*
Approach 
We can first reverse the LL and then add one till the time we don't have any carry.
After that we reverse the LL again and return the head.

Thinking of Test Cases like 9->9->9
and 9->7->9

*/
class Solution
{
    private:
     Node*  reverseLL(Node *head)
    {
        if(!head or !head->next)
        return head;
        Node *next,*prev=NULL;
        while(head!=NULL)
        {
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
        
        
    }
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
         Node *reverseHead=reverseLL(head);
         Node *curr=reverseHead;
         int carry=1;
         while(carry==1 and curr)
         {
             if(curr->data==9)
             {
                 curr->data=0;
                 if(curr->next)
                 curr=curr->next;
                 else {
                    curr->next=new Node(1);
                    carry=0;
                 }
                 
             }
             else {
                 curr->data=curr->data+1;
                 break;
             }
         }
         return reverseLL(reverseHead);
         
    }
};