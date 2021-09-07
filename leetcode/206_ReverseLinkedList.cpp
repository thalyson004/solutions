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
    ListNode* reverseList(ListNode* head) {
        vector<int> list;
        ListNode *cur = head;
        while(cur){
            list.push_back(cur->val);
            cur = cur->next;
        }

        cur = head;
        while(cur){
            cur->val = list.back();
            list.pop_back();
            cur = cur->next;
        }
        return head;
    }
};
