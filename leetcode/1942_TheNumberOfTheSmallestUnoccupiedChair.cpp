class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<bool> chair(n+5);

        vector< pair<int, pair<int,int>>  > actions;
        
        for(int i = 0; i < n; i++){
            actions.push_back( {times[i][1], {0, i} } );
            
            actions.push_back( {times[i][0], {1, i} } );
            
        }
        sort(actions.begin(), actions.end());
        map<int,int> oc;
        
        for(auto action:actions){
            if( action.second.first==1){
                int un = -1;
                for(int c=0; un<0; c++){
                    if(!chair[c]){
                        chair[c]=true;
                        un = c;
                        oc[action.second.second]= un;
                        if(action.second.second==targetFriend) return un;
                    }
                }
            }else{
                chair[ oc[action.second.second ] ] = false;
            }
        }
        
        
        return 0;
    }
};
