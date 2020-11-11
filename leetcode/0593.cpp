class Solution {
public:
    double eps = 1e-9;
    
    double distance(vector<int> &p1, vector<int> &p2){
        return sqrt( pow(p1[0]-p2[0],2) + pow(p1[1]-p2[1],2) );
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points({p1,p2,p3,p4});
        
        vector<double> distances;
        for(int i = 0; i < 4; i++){
            for(int j = i+1; j < 4; j++){
                distances.push_back( {distance(points[i], points[j])} );
            }
        }
        
        sort(distances.begin(), distances.end());
        double side = distances[0];
        double diangonal = distances[0]*sqrt(2);
        if(abs(distances[0])<eps) return false;
        if(abs(distances[3]-side)>eps) return false;
        if(abs(distances[4]-diangonal)>eps) return false;
        
        return true;
    }
};
