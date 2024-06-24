/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/* Here we can use 3 solutions:
    1. Hashing : stores the first linkedlist in a hash and then check the hashes while transversing through the second list
    2. caluclating length : caluclate length of both lists then have bigger list travel the difference between their lengths to get them at the same verical level and then check for intersection
    3. Optimal solution : the solution given below Tc:  O(max(n1,n2)) , SC: O(1)
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1 != temp2){ // leaves if headA = headB
            temp1 = temp1->next;
            temp2 = temp2->next;

            if(temp1 == temp2){ // this condition will handle the intersection points as well as if there is no intersection point then both will be null
                return temp2; // we can return anyone
            }
            if(temp1 == NULL) temp1 = headB;
            if(temp2 == NULL) temp2 = headA;

        }
        return temp1; // this takes care if both the heads are same
    }
};
// @lc code=end

