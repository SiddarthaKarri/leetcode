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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) 
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* beforeLeft = dummy;
        for (int i = 1; i < left; i++)
            beforeLeft = beforeLeft->next;
        ListNode* prev = nullptr;
        ListNode* curr = beforeLeft->next;
        ListNode* leftNode = curr;
        for (int i = left; i <= right; i++) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        beforeLeft->next = prev;
        leftNode->next = curr;
        return dummy->next;
    }
};