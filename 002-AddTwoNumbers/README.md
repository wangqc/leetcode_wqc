# AddTwoNumbers

## 问题描述

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)

Output: 7 -> 0 -> 8

## 问题分析

此题乍一看，最直观想法是直接每个链表遍历一遍，然后通过正常的整数相加，再将和转换成为链表返回即可。

可是细想会知道，题目没有限定链表长度，也就是转换为整数之后可能就已知数据类型（int ，long等）是存储不下的。换言之，这道题其实就是一道跟高精度相关的题。

高精度的解题思路就是自己手动对加数每一位相加，判断进位等。因此很容易就有了咱们的第一个版本。

### 版本一

c++代码如下：

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

想法很简单，就是

1. 双指针同时遍历两个链表，将加和模十的值赋给新生成的节点，再给进位up赋值（如果有值的话）
2. 双指针遍历肯定会有一个先到头；再遍历剩下的那个链表，因为不知道哪一个，没有判断，就再写两个循环，循环内操作类似；
3. 当两个链表都遍历完，判断up是否为1，决定是否需要再加入值为1的节点。


### 版本二

版本一提交后发现运行时间为48ms，代码效率只优于其他8%的代码，再看看代码，还有好些可以修改的地方，从而产生了版本二，代码如下：

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
       
新版本不再生成新的节点，直接将值相加之后赋给第一个链表，这样可以节省了生成新节点的时间。还是双指针遍历，跳出循环之后将tmp2（如果有的话）接到tmp1后面，继续循环，比版本一少了一次循环，最后还是判断是否进位。

版本二修改后运行时间为36ms，代码效率已经优于其他100%的代码了。


## 更进一步

照例查看Discuss中，有以下代码：

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode c1 = l1;
        ListNode c2 = l2;
        ListNode sentinel = new ListNode(0);
        ListNode d = sentinel;
        int sum = 0;
        while (c1 != null || c2 != null) {
            sum /= 10;
            if (c1 != null) {
                sum += c1.val;
                c1 = c1.next;
            }
            if (c2 != null) {
                sum += c2.val;
                c2 = c2.next;
            }
            d.next = new ListNode(sum % 10);
            d = d.next;
        }
        if (sum / 10 == 1)
            d.next = new ListNode(1);
        return sentinel.next;
    }

可以看到代码更加简洁，因为在while循环中是通过||运算符，省略了之后再单独判断的步骤。

当然，可以将sum/10也作为判断条件置入while循环判断条件中，又可以省略两行代码，就是这么任性！