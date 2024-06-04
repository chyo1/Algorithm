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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode();
        ListNode* big = new ListNode();

        ListNode* result = small;
        ListNode* bigResult = big;
        ListNode* now = head;

        while (now) {
            if (now->val < x) {
                small->next = now;
                small = small->next; 
            }
            else {
                big->next = now;
                big = big->next; 
            }
            now = now->next;
        }
        small->next = bigResult->next;
        big->next = NULL;
        return result->next;
    }
};