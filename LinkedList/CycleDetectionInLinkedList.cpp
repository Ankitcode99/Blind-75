class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode *slow=head, *fast=head->next;
        while(slow!=NULL && fast!=NULL){
            if(slow == fast){
                return true;
            }
            slow=slow->next;
            if(fast->next!=NULL)
                fast = fast->next->next;
            else
                fast=fast->next;
        }
        return false;
    }
};