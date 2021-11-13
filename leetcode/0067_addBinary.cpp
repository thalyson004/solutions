class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        bool remain = false;
        string ans = "";
        
        for(int i = 0; i < max(a.size(), b.size()); i++){
            ans.push_back(
                '0'+
                remain+
                (i<a.size() and a[i]=='1')+
                (i<b.size() and b[i]=='1'));
            
            if(ans.back()-'0'>=2){
                remain = true;
                ans.back()-=2;
            }else{
                remain = false;
            }
        }
        
        if(remain){
            ans.push_back('1');
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
