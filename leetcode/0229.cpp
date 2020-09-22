class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int na=-1, nb=-1, qa=0, qb=0;
        
        for(int x:nums){
            if((na==-1 and nb!=x) or (x==na) ){
                na = x;
                qa++;
            }else if( (na!=x and nb==-1) or (x==nb) ){
                nb = x;
                qb++;
            }else {
                qa--;
                qb--;
                if(qa==0) na = -1;
                if(qb==0) nb = -1;
            }
        }
        qa = 0;
        qb = 0;
        for(int x:nums){
            if(x==na) qa++;
            if(x==nb) qb++;
        }
        vector<int> ans;
        if(qa>nums.size()/3) ans.push_back(na);
        if(qb>nums.size()/3) ans.push_back(nb);
        return ans;
    }
};
