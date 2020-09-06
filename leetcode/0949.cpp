class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort( A.begin(), A.end() );
        string ans = "";
    
        do{
            int hour = 10*A[0] + A[1];
            int minute = 10*A[2] + A[3];
            if(hour<24 and minute < 60 and hour*60+minute < 24*60){
                string cur="";
                cur.push_back( ('0'+A[0]) );
                cur.push_back( ('0'+A[1]) );
                cur.push_back( ':' );
                cur.push_back( ('0'+A[2]) );
                cur.push_back( ('0'+A[3]) );
            
                ans = max(ans, cur);
            }
        }while( next_permutation(A.begin(), A.end() ) );
            
        return ans;
    }
};
