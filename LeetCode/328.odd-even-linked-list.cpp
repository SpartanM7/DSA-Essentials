/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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

/* This question can have 2 solutions 
    1. calculating no. of 0s, 1s, and 2s and then replacing the data
    2. creating 3 different LL for all the 3 no. and connecting them afterwards
*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* o = head; // odd head
        ListNode* e = head->next; // even head
        ListNode* eHead = e; // storing even head

        while(e && e->next != NULL && o && o->next){
            o->next = o->next->next; // connecting odd to odd
            e->next = e->next->next; // connecting even to even 

            o = o->next; // updating odd to its next list
            e = e->next; // updating even to its next list
        }
        o->next = eHead; // connecting odd last to even head
        return head; // returning the head
       
    }
};
// @lc code=end

