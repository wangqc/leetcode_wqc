ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *head = l1;
       ListNode *tmp1 = l1, *tmp2 = l2;
       ListNode *traceL1;
       int singleSum;
       int up = 0;
       while(tmp1 && tmp2){
           singleSum = tmp1->val + tmp2->val + up;
           tmp1->val = singleSum % 10;
           up = singleSum/10;
           traceL1 = tmp1;
           tmp1 = tmp1->next;
           tmp2 = tmp2->next;
       }
       if(tmp2){
           traceL1->next = tmp2;
           tmp1 = tmp2;
       }
       while(tmp1){
           singleSum = tmp1->val + up;
           if(singleSum != 10){
               tmp1->val = singleSum;
               up = 0;
               return head;
           }
           else {
               tmp1->val = singleSum - 10;
               up = 1;
               traceL1 = tmp1;
               tmp1 = tmp1->next;
           }
       }
       if(up == 1){
           ListNode *tail = new ListNode(1);
           traceL1->next = tail;
       }
       return head;
    }
