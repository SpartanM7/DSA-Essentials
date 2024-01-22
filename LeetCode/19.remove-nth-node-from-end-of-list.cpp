/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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

/* This question has 2 solutions i know of right now
    1. calculating lenght of LL and then size-N
    2. Using two pointers approach to find the node which needs to be deleted
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        if(head->next == NULL){
            if(n == 1) return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* ans = new ListNode();
        for(int i = 0; i < n; i++) fast = fast->next;

        if(fast == NULL){
            ans = head->next;
            delete head;
            return ans;

        }
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
    }
    ans = slow->next;
    slow->next = slow->next->next;
    delete ans;
    return head;
    }
};
// @lc code=end

