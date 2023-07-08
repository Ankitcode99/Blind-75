class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2){
            return NULL;
        } 
        if(!list1&&list2){
            return list2;
        }
        if(list1&&!list2)
            return list1;


        ListNode *l1=list1, *l2=list2, *prev=NULL;
        if(l1->val > l2->val){
            swap(l1,l2);
        }
        prev = l1;
        ListNode* newHead = prev;
        l1 = l1->next;

        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                prev->next = l1;
                l1 = l1->next;
                prev = prev->next;
            }else{
                prev->next = l2;
                l2 = l2->next;
                prev = prev->next;
            }
        }

        if(l1!=NULL){
            prev->next = l1;
        }

        if(l2!=NULL){
            prev->next = l2;
        }

        return newHead;
    }
};