class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {

        vector<pair<int,int>> xs, ys;
        for(vector<int> rectangle : rectangles){
            xs.push_back( {rectangle[0], 1} );
            xs.push_back( {rectangle[2], -1} );
            ys.push_back( {rectangle[1], 1} );
            ys.push_back( {rectangle[3], -1} );
        }

        auto check = [](vector<pair<int,int>> &v){
            sort(v.begin(), v.end());
            int cuts = 0, count = 0;
            int id = 0;
            int actual = v[0].first;
            while(id < v.size()){
                int current = actual;
                int removed = false;
                // Remove
                while( actual == current and v[id].second == -1){
                    count--;
                    removed = true;
                    id++;
                    actual = id < v.size() ? v[id].first : -1;
                }
                if(id and !count) cuts+=removed;
                // Add
                while( actual == current ){
                    count++;
                    id++;
                    actual = id < v.size() ? v[id].first : -1;
                }

            }
            return cuts>=3;
        };

        return check(xs) or check(ys);
        
    }
};
