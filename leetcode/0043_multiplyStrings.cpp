class Solution {
public:
    
    string multiply(string num1, char num2){
        reverse(num1.begin(), num1.end());
        
        int remain = 0;
        for(int i = 0; i < num1.size(); i++){
            int value = (num1[i]-'0')*(num2-'0') + remain;
            remain = value/10;
            num1[i] = (value%10)+'0';
        }
        
        if(remain){
            num1.push_back( '0'+remain );
        }
        
        reverse(num1.begin(), num1.end());
        
        return num1;
    }
    
    string sum(string num1, string num2){
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int remain = 0;
        for(int i = 0; i < max(num1.size(), num2.size()); i++){
            int value1 = i < num1.size() ? (num1[i]-'0') : 0;
            int value2 = i < num2.size() ? (num2[i]-'0') : 0;
            int value = value1+value2+remain;
            remain = value/10;
            
            if(i < num1.size()){
                num1[i] = (value%10)+'0';
            }else{
                num1.push_back((value%10)+'0');
            }
        }
        
        if(remain){
            num1.push_back(remain+'0'); 
        }
        
        reverse(num1.begin(), num1.end());
        
        return num1;
    }
    
    string multiply(string num1, string num2) {
        string ans = "0";
        
        for(int i = 0;i < num2.size(); i++){
            string result = multiply(num1, num2[ num2.size()-1-i ]) + string(i, '0');
            ans = sum(ans, result);
            reverse(ans.begin(), ans.end());
            while(ans.size()>1 and ans.back()=='0') ans.pop_back();
            reverse(ans.begin(), ans.end());
        }
        
        return ans;
    }
};
