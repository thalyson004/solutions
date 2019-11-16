/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() {}
    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        Node* temp=root;
        
        for(Node* i = root; i ; i = i->next ){
            if(temp==i){
                temp = temp->next;
                while(temp and temp->left==temp->right ) temp = temp->next;
            }
            
            if(i->left){
                if(i->right) i->left->next = i->right;
                else if( temp and temp->left ) i->left->next = temp->left;
                else if( temp ) i->left->next = temp->right;
            }
            
            if(i->right){
                if( temp and temp->left ) i->right->next = temp->left;
                else if(temp) i->right->next = temp->right;
            }
            if(!temp) break;
        }
        
        temp = root;
        while( temp != NULL and temp->left==temp->right ) temp = temp->next;
        
        if(temp and temp->left){
            connect(temp->left);
        }else if(temp and temp->right){
            connect(temp->right);
        }
        return root;
    }
};
