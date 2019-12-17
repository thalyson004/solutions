class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort( nums.begin(), nums.end() );
        
        vector< vector<int> > ans;
        
        for( int a = 0 ; a < nums.size(); a++ ){
            
            int b = a+1;
            int c = nums.size()-1;
            
            while( b<c ){
                int sum = nums[b]+nums[c];
                if( sum < -nums[a] ){
                    b++;
                }else if( sum > -nums[a] ){
                    c--;
                }else{
                    ans.push_back( { nums[a], nums[b], nums[c] } );
                    while( b < c and nums[b]==nums[b+1] )b++;
                    b++;
                }
            }
            
            while( a < nums.size()-1 and nums[a]==nums[a+1] )a++;
        }
        return ans;
    }
};
