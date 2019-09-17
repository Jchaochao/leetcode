//
//  test.cpp
//  Leetcode
//
//  Created by Zhao Jin on 9/16/19.
//  Copyright © 2019 Zhao Jin. All rights reserved.
//

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*result = new ListNode(0);
        ListNode*temp = result;
        ListNode* subl1 = l1;
        ListNode* subl2 = l2;
        int addOne = 0;
        while(subl1 != NULL || subl2 != NULL || addOne != 0 )
        {
            if(subl1 == NULL &subl2 == NULL)
            {
                temp->val = addOne;
                addOne = 0;

            }
            else if(subl1 == NULL)
            {
                temp->val = (subl2->val + addOne) % 10;
                addOne = (subl2->val + addOne) >=10 ? 1 : 0;
                subl2 = subl2->next;

            }
            else if(subl2 == NULL)
            {
                temp->val = (subl1->val + addOne) % 10;
                addOne = (subl1->val + addOne) >=10 ? 1 : 0;
                subl1 = subl1->next;

            }

            else
            {
                temp->val = ((subl1->val + subl2->val)  + addOne) % 10;
                addOne = (subl1->val + subl2->val + addOne) >= 10 ? 1 : 0;
                subl1 = subl1->next;
                subl2 = subl2->next;

            }
            if(subl1 != NULL || subl2 != NULL || addOne != 0 )
            {
                temp->next = new ListNode(0);
                temp = temp->next;
            }

        }
        return result;
    }
};
