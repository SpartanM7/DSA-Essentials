/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    // function to reverse the LL
    ListNode* reverseLL(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseLL(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;

    };

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        // finding the middle list
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // reversing the 2nd half of the list
        ListNode* newHead = reverseLL(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;
        while(second != NULL){
            if(first->val != second->val) { 
                reverseLL(newHead);
                
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLL(newHead);

        return true;
        }
    };

// @lc code=end

