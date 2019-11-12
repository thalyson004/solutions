class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> Qstones;
        for(int s : stones) Qstones.push( s );
        
        while(Qstones.size()>1){
            int a = Qstones.top(); Qstones.pop();
            int b = Qstones.top(); Qstones.pop();
            if(a!=b){
                Qstones.push( a-b );
            }
        }
        return Qstones.size()?Qstones.top():0;
    }
};
