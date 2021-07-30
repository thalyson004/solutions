struct Node{
    int value;
    int sum;
    Node* children[26];
    
    Node(){
        value = sum = 0;
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class MapSum {
public:
    Node *root;
    
    MapSum() {
        root = new Node();    
    }
    
    void insert(string key, int val) {
        // Add
        Node *cur = root;
        for(char c: key){
            cur->sum+=val;
            
            if( cur->children[c-'a']==nullptr ){
                cur->children[c-'a']= new Node();
            }
            cur = cur->children[c-'a'];
        }
        
        // Subtract
        Node *sub = root;
        for(char c:key){
            sub->sum-=cur->value;
            sub = sub->children[c-'a'];
        }
        
        
        cur->sum+=(val-cur->value);
        cur->value = val;
    }
    
    int sum(string key) {
        Node *cur = root;
        for(char c:key){
            if( cur->children[c-'a']==nullptr )
                return 0;
            cur = cur->children[c-'a'];
        }
        return cur->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
