class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev=head;
        ListNode *tmp=prev;
        while(prev){
            while(tmp&&tmp->val==prev->val){
                tmp=tmp->next;
            }
            prev->next=tmp;
            prev=tmp;
        }
        return head;
    }
};
