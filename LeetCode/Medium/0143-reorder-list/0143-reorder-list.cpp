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
    void reorderList(ListNode* head) {
        vector<ListNode*> arr;
        ListNode* temp = head;
        while(temp!=nullptr){
            arr.push_back(temp);
            temp = temp->next;
        }
        temp=head;
        int left=1,right=arr.size()-1,i=0;
        while(i<arr.size()){
            if(i%2==0){
                temp->next = arr[right];
                right--;
            }else{
                temp->next = arr[left];
                left++;
            }
            i++;
            temp = temp->next;
        }
        temp->next = nullptr;
    }
};