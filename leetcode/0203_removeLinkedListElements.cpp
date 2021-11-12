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
    ListNode* removeElements(ListNode* head, int val, ListNode* prev=nullptr) {
        if(head == nullptr) return nullptr;
        ListNode* ans = head;
        
        if(head->val == val){
            ans = removeElements(head->next, val, prev);
            delete head;
            return ans;
        }else{
            ans->next = removeElements(head->next, val, head);
            return ans;
        }
    }
};
