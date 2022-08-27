// Link to original problem: https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carry = 0;
        ListNode* result = new ListNode(l1->val + l2->val);
        ListNode* current = new ListNode();
        ListNode* previous = new ListNode();
        
        if(result->val >= 10)
        {
            carry = 1;
            result->val = result->val - 10;
        }
        
        previous = result;
        
        while(l1->next && l2->next)
        {
            l1 = l1->next;
            l2 = l2->next;
            
            if(carry == 1)
                current->val = l1->val + l2->val + 1;
            else
                current->val = l1->val + l2->val;
            
            if(current->val >= 10)
            {
                carry = 1;
                current->val = current->val - 10;
            }
            else
                carry = 0;
            
            previous->next = current;
            previous = previous->next;
            current = new ListNode();
        }
        
        if(l1->next)
        {
            previous->next = l1->next;
            
            while(carry == 1 && l1->next)
            {
                l1 = l1->next;
                l1->val = l1->val + 1;
                if(l1->val >= 10)
                {
                    carry = 1;
                    l1->val = l1->val - 10;
                }
                else
                    carry = 0;
            }
            previous = l1;
        }
        else if(l2->next)
        {
            previous->next = l2->next;
            
            while(carry == 1 && l2->next)
            {
                l2 = l2->next;
                l2->val = l2->val + 1;
                if(l2->val >= 10)
                {
                    carry = 1;
                    l2->val = l2->val - 10;
                }
                else
                    carry = 0;
            }
            previous = l2;
        }
        
        
        if(carry == 1)
        {
            previous->next = new ListNode(1);
        }
        
        return result;
    }
};
