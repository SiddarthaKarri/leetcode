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
        ListNode ls(0),gt(0);
        ListNode *hls=&ls, *hgt=&gt;
        while(head){
            if(head->val<x){
                hls->next=head;
                hls = hls->next;
            }else{
                hgt->next=head;
                hgt=hgt->next;
            }
            head = head->next;
        }
        hgt->next=nullptr;
        hls->next=gt.next;
        return ls.next;
        // vector<ListNode*> arr;
        // ListNode* temp=head;
        // while(temp!=NULL){
        //     arr.push_back(temp);
        //     temp = temp->next;
        // }
        // ListNode* hd=NULL,*fst=NULL;
        // for(auto i:arr){
        //     if(i->val<x){
        //         if(hd==NULL){
        //             hd=i;
        //             fst=i;
        //         } else{
        //             fst->next=i;
        //             fst=i;
        //         }
        //     }
        // }
        // for(auto i:arr){
        //     if(i->val>=x){
        //         if(hd==NULL){
        //             hd=i;
        //             fst=i;
        //         } else{
        //             fst->next=i;
        //             fst=i;
        //         }
        //     }
        // }
        // if(fst) 
        //     fst->next = NULL;
        // return hd;
    }
};