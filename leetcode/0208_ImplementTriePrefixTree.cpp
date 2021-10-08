

class Trie {
    struct Node{
        vector<Node*> children;
        int count;
        Node(){
            children = vector<Node*>(26, nullptr);
            count = 0;
        }
    };
    
public:
    Node* root;
    
    Trie() {
        root = new Node();    
    }
    
    void insert(string word) {
        Node* cur = root;
        for(char letter: word){
            int id = letter-'a';
            
            if(cur->children[id]==nullptr) cur->children[id] = new Node();
            cur = cur->children[id];
        }
        cur->count++;
    }
    
    bool search(string word) {
        Node* cur = root;
        for(char letter: word){
            int id = letter-'a';
            
            if(cur->children[id]==nullptr) return false;
            cur = cur->children[id];
        }
        return cur->count;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(char letter: prefix){
            int id = letter-'a';
            
            if(cur->children[id]==nullptr) return false;
            cur = cur->children[id];
        }
        return true;
    }   
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
