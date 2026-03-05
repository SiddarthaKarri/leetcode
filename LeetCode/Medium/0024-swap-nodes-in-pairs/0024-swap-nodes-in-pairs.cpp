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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* t1,*t2,*prev;
        t1=head;
        t2=head->next;
        t1->next = t2->next;
        t2->next = t1;
        head=t2;
        prev=t1;
        while(prev->next && prev->next->next){
            t1 = prev->next;
            t2=t1->next;
            t1->next=t2->next;
            t2->next=t1;
            prev->next = t2;
            prev = t1;
        }
        return head;
    }
};