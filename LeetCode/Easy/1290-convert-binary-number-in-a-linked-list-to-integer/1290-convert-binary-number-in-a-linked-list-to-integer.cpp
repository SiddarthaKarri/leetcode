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
#include <cmath>
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        int res = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        temp = head;
        for (int i = (count - 1); i >= 0; i--) {
            res += (temp->val) * (pow(2, i));
            temp = temp->next;
        }
        return res;
    }
};