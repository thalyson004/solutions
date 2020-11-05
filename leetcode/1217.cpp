class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int pos[2] = {0,0};
        for(int p:position) pos[ p%2 ]++;
        return min(pos[0], pos[1]);
    }
};
