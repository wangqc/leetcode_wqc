/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !(head->next)){
            return true;
        }
        ListNode * fast, * slow;
        fast = slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = transverseList(slow->next);
        slow = slow->next;
        fast = head;
        while(slow != NULL){
            if(fast->val != slow->val){
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
    
    ListNode * transverseList(ListNode* head){
        ListNode * pre, *next;
        next = NULL;
        while(head->next){
            pre = head->next;
            head->next = next;
            next = head;
            head = pre;
        }
        head->next = next;
        return head;
    }
};
