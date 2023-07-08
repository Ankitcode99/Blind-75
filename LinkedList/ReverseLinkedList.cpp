class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return NULL;

        ListNode *prev=NULL, *curr=head, *next=head;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } 
        return prev;
    }
};