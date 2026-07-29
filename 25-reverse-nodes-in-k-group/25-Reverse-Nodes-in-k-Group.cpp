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

    ListNode* findKNode(ListNode* temp,int k){
        int cnt =0;
        while(temp!=NULL){
            cnt++;
            if(cnt==k){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* back=NULL;
        while(head!=NULL){
            ListNode* temp = head->next;
            head->next = back;
            back = head;
            head=temp;
        }
        return back;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* kNode = NULL;
        ListNode* nextNode = NULL;
        ListNode* prevNode = NULL;
        while(temp != NULL){
            kNode = findKNode(temp,k);
            if(kNode == NULL){
                if(prevNode) prevNode->next = temp;
                break;
            }
            nextNode = kNode->next;
            kNode->next=NULL;
            reverseLL(temp);
            if(temp == head){
                head = kNode;
            } else {
                prevNode->next = kNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};