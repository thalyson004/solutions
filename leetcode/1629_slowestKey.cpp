class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ansc = ' ';
        int longest = 0;
        int last = 0;
        for(int i = 0; i < releaseTimes.size(); i++){
            int time = releaseTimes[i]-last;
            last = releaseTimes[i];
            
            if(make_pair(longest, ansc) < make_pair(time, keysPressed[i]) ){
                ansc = keysPressed[i];
                longest = time;
            }
        }
        
        return ansc;
    }
};
