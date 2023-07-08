using pi = pair<int,ListNode*>;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
                pq.push({lists[i]->val,lists[i]});
        }
        ListNode* start=NULL;
        ListNode* prev=NULL;
        
        while(pq.size())
        {
            pi top = pq.top();
            pq.pop();
            int val = top.first;
            ListNode* temp = new ListNode(val);
            if(prev!=NULL)
            {
                prev->next = temp;
            }
            else
            {
                start=temp;
            }
            
            prev=temp;
            
            if(top.second->next)
            {
                pq.push({top.second->next->val,top.second->next});
            }
        }
        return start;
    }
};