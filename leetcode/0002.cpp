class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *a = ans;
        while(l1!=NULL){
            a->val += l1->val;
            if(l1->next!=NULL){
                a->next = new ListNode(0);
            }
            a=a->next;
            l1=l1->next;
        }
        a = ans;
        while(l2!=NULL){
            a->val += l2->val;
            if(a->next==NULL and l2->next!=NULL ){
                a->next = new ListNode(0);
            }
            a=a->next;
            l2=l2->next;
        }
        a = ans;
        while(a!=NULL){
            if(a->val > 9){
                if(a->next==NULL) a->next = new ListNode(0);
                a->next->val += a->val/10;
                a->val %= 10;
            }
            a=a->next;
        }
        return ans;
    }
};
