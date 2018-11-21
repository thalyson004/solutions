struct myclass {
    bool operator() (string i,string j) { 
        string a = i+j;
        string b = j+i;
        return a<b;
    }
} myobject;


class Solution {
public:
    string intToString(int x){
        string s;
        do{
            s.push_back( '0'+x%10 );
            x/=10;
        }while(x);
        reverse(s.begin(), s.end());
        return s;
    }
    bool compare (string a, string b) {

        return a<b;
    }
    string largestNumber(vector<int>& nums) {
        string s;
        vector<string> v;
        for(int x:nums){
            v.push_back( intToString(x) );
        }
        sort(v.begin(), v.end(), myobject);
        reverse(v.begin(), v.end());
        for(string x: v) s = s+x;
        if(s[0]=='0')return "0";
        return s;
    }

};