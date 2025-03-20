class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<pair<int, int>> G[int(1e5)+5];
        int component[int(1e5)+5] = {0};
        int bitwise[int(1e5)+5] = {0};

        function<void(int, int)> dfs = [&](int v, int comp) {
            if(component[v]) return;
            if(v==comp) bitwise[v] = (((1<<30)-1)<<1)+1;
            component[v] = comp;

            for(pair<int,int> edge: G[v]){
                int u = edge.first;
                int w = edge.second;

                bitwise[comp] &= w;
                dfs(u, comp);
            }
        };

        for(vector<int> edge : edges){
            int v = edge[0]+1;
            int u = edge[1]+1;
            int w = edge[2];
            G[v].push_back({u, w});
            G[u].push_back({v, w});
        }


        vector<int> ans;
        for(vector<int> q : query){
            int v = q[0]+1;
            int u = q[1]+1;

            if(!component[v]) dfs(v, v);
            if(!component[u]) dfs(u, u);

            if(component[v] != component[u]) ans.push_back(-1);
            else ans.push_back( bitwise[component[v]] );
        }
        return ans;
    }
};
