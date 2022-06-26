//https://leetcode.com/problems/linked-list-cycle/
bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next and fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
    }