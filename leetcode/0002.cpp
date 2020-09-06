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
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *resp=NULL, *last;
        int s = 0;
        
        while(l1!=NULL || l2!=NULL || s){
            if(l1!=NULL){
                s+=l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                s+=l2->val;
                l2 = l2->next;
            }
            if( resp==NULL ) resp = last = new ListNode( s%10 );
            else last->next = new ListNode(s%10), last = last->next;
            s /= 10;
        }
        
        return resp;
    }
};
