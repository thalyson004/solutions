class Solution {
public:
    
    /// Return True if A inside B
    bool inside(vector<int> a, vector<int> b){
        return a[0]>=b[0] and a[1]>=b[1] and a[2]<=b[2] and a[3]<=b[3];
    }
    
    /// Return True if A intersect B
    bool intersect(vector<int> a, vector<int> b){
        return (a[2]>b[0] and a[3]>b[1]) and (a[0]<b[2] and a[1]<b[3]);
    }
    
    /// Return area of rectangle r
    long long area(vector<int> a){
        long long s1 = a[0]-a[2];
        long long s2 = a[1]-a[3];
        return s1*s2;
    }

    
    int rectangleArea(vector<vector<int>>& rec) {
        vector<vector<int>> separated;
        long long ans = 0;
        
        sort(rec.begin(), rec.end());
        
        for(auto cur: rec){
            vector<vector<int>> news;
            int needInsert = true;
            
            for(auto prev:separated){
               
                if( inside(prev, cur) ){
                    continue;
                }
                if( inside(cur, prev) ){
                    needInsert = false;
                    news.push_back(prev);
                    continue;
                }
                
                if( intersect(cur, prev) ){
                    printf("Intersect!\n");
                    // left
                    if(cur[0]>prev[0]){
                        news.push_back( {prev[0], prev[1], cur[0], prev[3]} );
                    }
                    // right
                    if(cur[2]<prev[2]){
                        news.push_back( {cur[2], prev[1], prev[2], prev[3]} );
                    }
                    // top
                    if(cur[3]<prev[3]){
                        news.push_back( {max(prev[0], cur[0]), cur[3], 
                                         min(prev[2], cur[2]), prev[3]} );
                    }
                    // bottom
                    if(cur[1]>prev[1]){
                        news.push_back( {max(prev[0], cur[0]), prev[1], 
                                         min(prev[2], cur[2]), cur[1]} );
                    }
                }else{
                    news.push_back(prev);
                }
            }
            
            if(needInsert) news.push_back( cur );
                
            separated = news;
        }
        
        long long mod = 1e9 + 7;
        for(auto r: separated){
            ans = (ans+area(r))%mod;
        }
        return ans;
    }
};

