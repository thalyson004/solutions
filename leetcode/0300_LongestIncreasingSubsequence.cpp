
struct fenwick_pre_max {
    vector<int> bit;
    
    fenwick_pre_max(int len){
        bit = vector<int>(len+5);
    }
    
    void update(int p, int value){
        while(p<bit.size()){
            bit[p] = max(bit[p], value);
            p += ( p& -p);
        }
    }
    
    int query(int p){
        int ans = 0;
        while(p){
            ans = max(ans, bit[p]);
            p -= (p & -p);
        }
        return ans;
    }
};

class Solution {
public:
    
    vector<int> compress(vector<int> &v){
        vector<int> ans;
        vector<int> order = v;
        sort(order.begin(), order.end());
        order.erase(unique(order.begin(), order.end()), order.end());
             
        int id = 1;
        map<int,int> ids;
            
        for(int value: order){
            ids[value] = id++;
        }
        for(int value: v){
            ans.push_back( ids[value] );
        }
             
        return ans;
    }
    
    
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> comp = compress(nums);
        fenwick_pre_max tree(comp.size());
        
        int ans = 0;
        
        for(int value: comp){
            int longest = tree.query(value-1)+1;
            tree.update(value, longest);
            ans = max(ans, longest);
        }
        
        return ans;
    }
};
