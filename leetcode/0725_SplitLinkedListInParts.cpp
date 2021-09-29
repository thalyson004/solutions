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
    int size(ListNode *head){
        if(!head) return 0;
        else return 1 + size(head->next);
    }
    
    void solve(ListNode *head, ListNode *prev, int i, vector<ListNode*> &ans, int len, int remain){
        if(!head) return;
        else{
            ListNode *next = head->next;
            
            if(i<=0){
                if(i==0 and remain){
                    remain--;
                }else{
                    if(prev) prev->next = nullptr;
                    ans.push_back(head);
                    i = len;    
                }
            }
            
            solve(next, head, i-1, ans, len, remain);
        }
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = size(head);
        
        vector<ListNode*> ans;
        
        solve(head, nullptr, -1, ans, len/k, (len%k) );
        while(ans.size()<k) ans.push_back(nullptr);
        
        return ans;
    }
};
