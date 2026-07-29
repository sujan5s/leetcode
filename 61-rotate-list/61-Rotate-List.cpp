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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        int cnt = 0;
        int n=0;
        ListNode* temp = head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        k = k %n;
        if(k==0){
            return head;
        }
        while(cnt != k){
            ListNode* temp = head;
            ListNode* nextNode = NULL;
            cnt++;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            nextNode= temp->next;
            nextNode->next = head;
            head = nextNode;
            temp->next = NULL;
        }
        return head;
    }
};