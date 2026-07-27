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
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        int cnt = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int stop = cnt - n;
        if(stop==0){
            temp =head;
            head = temp -> next;
            delete temp;
            return head;
        }
        cnt =0;
        temp = head;
        while(cnt != stop-1){
            cnt++;
            temp = temp->next;
        }
        ListNode* del = temp->next;
        if(del->next != NULL){
            temp->next = del->next;
            
        }else{
            temp->next=NULL;
        }
        delete del;
        return head;
    }
};