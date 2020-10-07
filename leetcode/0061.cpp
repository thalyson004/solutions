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
    int getSize(ListNode *cur){
        if(cur==NULL) return 0;
        else return 1+getSize(cur->next);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        
        int len = getSize(head);
        k %= len;
        if(k){
            ListNode *lastNode = NULL;
            ListNode *newHead=head;
            for(int i = 0; i < len-k ; i++){
                lastNode = newHead;
                newHead = newHead->next;
            }
            lastNode->next = NULL;
            lastNode=newHead;
            while(lastNode->next!=NULL) lastNode = lastNode->next;
            lastNode->next = head;
            head = newHead;
        }
        return head;
    }
};
