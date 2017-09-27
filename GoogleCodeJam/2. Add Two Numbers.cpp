//
//  2.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/27/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//
/*
 You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 
 */
#include "Header.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int Length1 = 1, Length2 = 1;
    ListNode *nl1 = l1, *nl2 = l2, *result = l1;
    while (l1 -> next != NULL) {
        Length1++;
        l1 = l1 -> next;
    }
    while (l2 -> next != NULL) {
        Length2++;
        l2 = l2 -> next;
    }
    if (Length2 > Length1) {
        return addTwoNumbers(nl2, nl1);//传入参数已经改变，fiexd
    }
    else{
        
        int carry = 0;
        while (nl2 -> next != NULL) {
            int sum = (carry + nl1 -> val + nl2 -> val);
            nl1 -> val = sum % 10;
            carry = sum / 10;
            nl1 = nl1 -> next;
            nl2 = nl2 -> next;
        }
        int sum = (carry + nl1 -> val + nl2 -> val);
        nl1 -> val = sum % 10;
        carry = sum / 10;
        while(carry == 1) {
            if (nl1 -> next == NULL) {
                ListNode* a1 = new ListNode(1);//添加节点应使用new来进行操作
                nl1 -> next = a1;
                carry = 0;
            }
            else
            {
                nl1 = nl1 -> next;
                int sum = carry + nl1 -> val;
                nl1 -> val = sum % 10;
                carry = sum / 10;
            }
        }
    }
    return result;
}
