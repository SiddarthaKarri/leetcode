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
        vector<ListNode*> arr;
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp);
            temp = temp->next;
        }
        ListNode* hd=NULL,*fst=NULL;
        for(auto i:arr){
            if(i->val<x){
                if(hd==NULL){
                    hd=i;
                    fst=i;
                } else{
                    fst->next=i;
                    fst=i;
                }
            }
        }
        for(auto i:arr){
            if(i->val>=x){
                if(hd==NULL){
                    hd=i;
                    fst=i;
                } else{
                    fst->next=i;
                    fst=i;
                }
            }
        }
        if(fst) 
            fst->next = NULL;
        return hd;
    }
};