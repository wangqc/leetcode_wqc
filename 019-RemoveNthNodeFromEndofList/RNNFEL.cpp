class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * first = head, * second = head;
        ListNode * pre = NULL;
        ListNode * tmp;
        for(int i = 0; i < n; i++){
            first = first->next;
        }
        while(first != NULL){
            first = first->next;
            pre = second;
            second = second->next;
        }
        if(pre == NULL){
            return head->next;
        }
        else{
            tmp = second;
            pre->next = second->next;
            tmp->next = NULL;
            free(tmp);
            return head;
        }
    }
};
