class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> pos;
        for(int i = 0; i < seats.size(); i++){
            if(seats[i]==1){
                pos.push_back(i);
            }
        }
        int ans = max(pos[0], int(seats.size())-pos.back()-1);
        for(int i = 1; i < pos.size(); i++){
            int dif = pos[i]-pos[i-1]-1;
            if(dif){
                ans = max(ans, (dif-1)/2 + 1 );    
            }
        }
        return ans;
    }
};
