/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        // missing the carry condition
        while(l1 != NULL || l2 != NULL || carry){
            sum = 0;
            if(l1 != NULL){
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry; 
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
    
        return dummyHead->next;
    }
};
// @lc code=end

