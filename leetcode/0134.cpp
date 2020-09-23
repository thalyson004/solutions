class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int sum = 0;
        int n = 0;
        for(int s = 0; s < 2*len; s++){
            int id = s%len;
            sum += (gas[id] -cost[id] );
            if(sum>=0) n++;
            else{
                sum = 0;
                n=0;
            }
            
            if(n==len){
                return (s-n+1+len)%len;
            }
        }
        return -1;
        
    }
};
