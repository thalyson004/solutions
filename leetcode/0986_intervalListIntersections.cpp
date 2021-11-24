class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0;
        int j = 0;
        
        vector<vector<int>> ans;
        
        while(i < firstList.size() and j < secondList.size()){
            
            // first inside
            if( firstList[i][0]>=secondList[j][0] and firstList[i][1]<=secondList[j][1] ){
                ans.push_back( firstList[i] );
            }else 
                // second inside
                if( firstList[i][0]<=secondList[j][0] and firstList[i][1]>=secondList[j][1] ){
                ans.push_back( secondList[j] );
            }else 
                // intersect
                if( min(firstList[i][1], secondList[j][1]) >= max(firstList[i][0], secondList[j][0]) ){
                ans.push_back( {max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1]) } );
            }
            
            if( firstList[i][1]<=secondList[j][1] ) i++;
            else j++;
        }
        
        return ans;
    }
};
