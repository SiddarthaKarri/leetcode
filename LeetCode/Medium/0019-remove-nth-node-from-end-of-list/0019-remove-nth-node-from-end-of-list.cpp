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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int size = 0;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        if (size == n) {
            return head->next;
        }
        ListNode* prev;
        temp = head;
        int delF = size - n;
        while (delF != 0) {
            prev = temp;
            temp = temp->next;
            delF--;
        }
        prev->next = temp->next;
        return head;
    }
};