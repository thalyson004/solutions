/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *turtle = head;
        ListNode *rabbit = head;
        while(turtle and rabbit and rabbit->next){
            turtle = turtle->next;
            rabbit = rabbit->next->next;
            if(turtle==rabbit){
                while(head!=turtle){
                    head=head->next;
                    turtle=turtle->next;
                }
                return head;
            }
        }
        
        return NULL;
    }
};
