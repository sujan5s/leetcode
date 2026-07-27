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

    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeTwoList(ListNode* leftHead,ListNode* rightHead){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(leftHead != NULL && rightHead!= NULL){
            if(leftHead->val < rightHead->val){
                temp->next = leftHead;
                temp = leftHead;
                leftHead = leftHead->next;
            } else {
                temp->next = rightHead;
                temp = rightHead;
                rightHead = rightHead->next;
            }
        }
        if(leftHead){
            temp->next = leftHead;
        } else{
            temp->next = rightHead;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* middle = findMiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;
        middle->next = nullptr;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        return mergeTwoList(leftHead,rightHead);
    }
};