class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * first = head, ** second = &head;
        ListNode * tmp;
        for(int i = 0; i < n; i++){
            first = first->next;
        }
        while(first != NULL){
            first = first->next;
            second = &((*second)->next);
        }
        tmp = *second;
        *second = (*second)->next;
        tmp->next = NULL;
        free(tmp);
        return head;
    }
};
