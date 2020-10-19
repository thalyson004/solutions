class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int ans = A.size()+1;
        for(int i = 1; i <= 6; i++){
            int ok = 1;
            int s = 0;
            for(int j=0; j <A.size(); j++){
                if(A[j]==i) continue;
                else{
                    if(B[j]==i) s++;
                    else ok = 0;
                }
            }
            if(ok==1){
                ans = min(ans, s);
            }
        }
        swap(A,B);
        for(int i = 1; i <= 6; i++){
            int ok = 1;
            int s = 0;
            for(int j=0; j <A.size(); j++){
                if(A[j]==i) continue;
                else{
                    if(B[j]==i) s++;
                    else ok = 0;
                }
            }
            if(ok==1){
                ans = min(ans, s);
            }
        }
        
        if(ans==A.size()+1) return -1;
        else return ans;
    }
};
