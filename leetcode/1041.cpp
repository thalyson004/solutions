class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0, y=0;
        int d=0;
        vector<pair<int,int>> di = vector<pair<int,int>>({{0,1},{1,0},{0,-1},{-1,0} });

        
        for(int i = 0; i < 4; i++){
            for(char c: instructions){
                if(c=='G'){
                    x+=di[d].first;
                    y+=di[d].second;
                }else if(c=='L'){
                    d--;
                }else{
                    d++;
                }
                d = (d+4)%4;
            }
            if( x+y==0 ){
                return true;
            }
        }
        
        return false;
    }
};
