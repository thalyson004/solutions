class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> mySet1;
        unordered_set<string> mySet2;
        int len = s.size();
        for(int i = 0; i+10<=len;i++){
            string cur = s.substr(i, 10);
            if(mySet1.count(cur)){
                mySet2.insert( cur );
            }else {
                mySet1.insert( cur );
            }
        }
        vector<string> ans;
        for(auto &it:mySet2) ans.push_back(it);
        return ans;
    }
};
