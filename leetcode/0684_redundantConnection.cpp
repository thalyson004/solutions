class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> group(n+1);
        
        for(int i = 1; i <= n; i++) group[i] = i;
        
        function<int(int)> leader = [&](int i){ return group[i] = (group[i]==i?i:leader(group[i])); };
        
        function<bool(int,int)> same = [&](int i, int j){ return leader(i) == leader(j);};
        
        function<void(int,int)> merge = [&](int i, int j){ group[leader(i)] = leader(j);};
        
        for(auto edge: edges){
            if(same(edge[0], edge[1])){
                return edge;
            }else{
                merge(edge[0], edge[1]);
            }
        }
        return vector<int>();
    }
};
