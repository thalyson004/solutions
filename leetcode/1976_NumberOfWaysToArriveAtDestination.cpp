class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = int(1e9) + 7;
        vector<long long> dist = vector<long long>(n, 1LL<<60);
        vector<int> ways = vector<int>(n, 0);
        vector<vector<pair<int,int>>> G = vector<vector<pair<int,int>>>(n);

        for(vector<int> road: roads){
            int v = road[0];
            int u = road[1];
            int w = road[2];
            G[v].push_back({u,w});
            G[u].push_back({v,w});
        }

        ways[0] = 1;
        dist[0] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> dj;
        dj.push({0LL,0});

        while(dj.size()){
            auto [w, v] = dj.top();
            dj.pop();
            if(dist[v]!=w) continue;

            for(auto [u, ww]: G[v]){
                if(dist[u] > w+ww ){
                    dist[u] = w+ww;
                    dj.push({dist[u],u});
                    ways[u] = ways[v];
                }else if(dist[u]==w+ww){
                    ways[u] = (ways[u]+ways[v])%mod;
                }
            }
        }

        return ways[n-1];
    }
};
