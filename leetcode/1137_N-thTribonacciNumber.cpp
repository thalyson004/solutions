class Solution {
public:
    int tribonacci(int n) {
        vector<int> tri = {0,1,1};
        while(tri.size()<=n){
            int len = tri.size();
            tri.push_back( tri[len-1]+tri[len-2]+tri[len-3] );
        }
        
        return tri[n];
    }
};
