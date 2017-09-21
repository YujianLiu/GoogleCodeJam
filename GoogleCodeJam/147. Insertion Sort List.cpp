//
//  147.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/20/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


ListNode* insertionSortList(ListNode* head)
{
    ListNode* currentPtr = head, newHead(0), *prevPtr = &newHead;
    newHead.next = currentPtr;
    head = head->next;
    currentPtr->next = NULL;
    while(head)
    {
        if(head->val > currentPtr->val && currentPtr->next != NULL)
        {
            prevPtr = currentPtr;
            currentPtr = currentPtr->next;
        }
        else if(head->val > currentPtr->val && currentPtr->next == NULL)
        {
            currentPtr->next = head;
            head = head->next;
            prevPtr = &newHead;
            currentPtr->next->next = NULL;
            currentPtr = prevPtr->next;
        }
        else
        {
            ListNode* temp = head;
            head = head->next;
            prevPtr->next = temp;
            temp->next = currentPtr;
            prevPtr = &newHead;
            currentPtr = newHead.next;
        }
    }
    
    return newHead.next;
}
