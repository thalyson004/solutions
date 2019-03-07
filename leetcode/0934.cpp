class Solution {
public:
    int n, m;
    vector<vector<int>> color;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    
    int limite(int a, int b){
        return a>=0 and b>=0 and a<n and b <m;    
        
    }
    
    void dfs1(int a, int b, queue< pair<int,int> > &fila){
        color[a][b] = -1;
        fila.push( {a,b} );
        for(int i = 0; i < 4; i++){
            int aa = a+dx[i];
            int bb = b+dy[i];
            if(limite(aa,bb) and color[aa][bb] == 1){
                dfs1(aa, bb, fila);
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        
        n = A.size();
        m = A[0].size();
        int total = 0;
        color = A;
        queue< pair<int,int> > fila;

        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(A[i][j]==1){
                dfs1(i,j, fila);
                i = j = m+n;
            }
        }
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(color[i][j]!=-1)
                color[i][j] = 1000000005;
        int ans=0;
   
        while( fila.size() ){
            int a = fila.front().first;
            int b = fila.front().second;
            fila.pop();
            
            for(int i = 0; i < 4; i++){
                int aa = a+dx[i];
                int bb = b+dy[i];
                if(limite(aa,bb) and color[aa][bb] != -1 and color[aa][bb]>color[a][b]+1 ){
                    color[aa][bb]=color[a][b]+1;
                    fila.push( {aa,bb} );
                    if(!ans and A[aa][bb]==1)
                        ans  = color[aa][bb];
                }
                
            }
        }
    
        return ans;
    }
};
