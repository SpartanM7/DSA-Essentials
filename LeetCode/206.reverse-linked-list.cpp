/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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

/* This solution can be solved in 2 ways(afaik)
    1. Data change : data from the list can be stored in stack and then passes to list again . TC : O(2n) , SC : (n), 2 pass solution
    2. Link change : this solution is given below. TC : O(n) SC : O(1). 1 pass solution
}
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // link change solution

       /* if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head; // temp to move forward
        ListNode* back = NULL; // stores the previous list so that link can be reversed
        ListNode* front = NULL; // stores the next list so that temp can move forward
        while(temp){
            front = temp->next;
            temp->next = back;
            back = temp;
            temp = front;
        }
        delete temp;
        delete front;
        return back; // as it becomes the new head*/


        // recursive solution
        
        // base case
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;

    }
};
// @lc code=end

