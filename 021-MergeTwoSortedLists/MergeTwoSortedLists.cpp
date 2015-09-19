class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * newHead, * cur, * first, * second;
        first = l1;
        second = l2;
        if(first == NULL){
            return l2;
        }
        if(second == NULL){
            return l1;
        }
        if(first->val < second->val){
            newHead = first;
            first = first->next;
        }
        else{
            newHead = second;
            second = second->next;
        }
        cur = newHead;
        for(; first != NULL && second != NULL;){
            if(first->val < second->val){
                cur->next = first;
                first = first->next;
            }
            else{
                cur->next = second;
                second = second->next;
            }
            cur = cur->next;
        }
        if(first){
            cur->next = first;
        }
        else if(second){
            cur->next = second;
        }
        return newHead;
        
    }
};
