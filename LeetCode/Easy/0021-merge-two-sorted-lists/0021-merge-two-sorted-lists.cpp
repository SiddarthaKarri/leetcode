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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        if (list1->val > list2->val)
            std::swap(list1, list2);
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* prev1 = NULL;
        while (cur1 && cur2) {
            if (cur1->val <= cur2->val) {
                prev1 = cur1;
                cur1 = cur1->next;
            } else {
                if (prev1)
                    prev1->next = cur2;
                prev1 = cur2;
                cur2 = cur2->next;
                prev1->next = cur1;
            }
        }
        if (cur2)
            prev1->next = cur2;
        return list1;
    }
};
