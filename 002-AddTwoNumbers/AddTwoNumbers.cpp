ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tmp1, *tmp2;
    tmp1 = l1, tmp2 = l2;
    ListNode *pseudoSumNode = new ListNode(0);
    int up = 0;
    bool isHead = true;
    ListNode *lastNode = pseudoSumNode;
    while(tmp1 && tmp2){
        ListNode *tmpSum = new ListNode(0);
        int singleSum;
        singleSum = tmp1->val + tmp2->val + up;
        tmpSum->val = singleSum%10;
        up = singleSum/10;
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
        lastNode->next = tmpSum;
        lastNode = tmpSum;
    }
    while(tmp1){
        ListNode *tmpSum = new ListNode(0);
        int singleSum;
        singleSum = tmp1->val + up;
        if(singleSum != 10){
            tmpSum->val = singleSum;
            lastNode->next = tmpSum;
            tmpSum->next = tmp1->next;
            up = 0;
            break;
        }
        else{
            tmpSum->val = 0;
            up = 1;
            lastNode->next = tmpSum;
            lastNode = tmpSum;
        }
        tmp1 = tmp1->next;
    }
    while(tmp2){
        ListNode *tmpSum = new ListNode(0);
        int singleSum;
        singleSum = tmp2->val + up;
        if(singleSum != 10){
            tmpSum->val = singleSum;
            lastNode->next = tmpSum;
            tmpSum->next = tmp2->next;
            up = 0;
            break;
        }
        else{
            tmpSum->val = 0;
            up = 1;
            lastNode->next = tmpSum;
            lastNode = tmpSum;
        }
        tmp2 = tmp2->next;
    }
    if(up){
        ListNode *tailNode = new ListNode(1);
        lastNode->next = tailNode;
    }
    return pseudoSumNode->next;
    }
