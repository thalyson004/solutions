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
    
    ListNode* getMid(ListNode* head){
        ListNode *prev=NULL;
        ListNode *turtle, *rabbit;
        turtle = rabbit = head;
        while(rabbit!=NULL and rabbit->next!=NULL){
            rabbit = rabbit->next->next;
            prev = turtle;
            turtle = turtle->next;
        }
        prev->next = NULL;
        return turtle;
    }
    
    ListNode* merge_sort(ListNode *head){
        if(head->next==NULL) return head;
        ListNode* mid = getMid(head);
        head = merge_sort(head);
        mid = merge_sort(mid);
        ListNode *start = new ListNode();
        ListNode *cur = start;
        while(head!=NULL and mid!=NULL){
            if(head->val < mid->val){
                cur->next = head;
                head = head->next;
            }else{
                cur->next = mid;
                mid = mid->next;
            }
            cur = cur->next;
        }
        if(head!=NULL) cur->next=head;
        else cur->next=mid;
        return start->next;
        
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL) return head;
        return merge_sort(head);
    }
};
