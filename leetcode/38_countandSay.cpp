class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        else {
            string cur = countAndSay(n-1);
            string ans = "";
            int count = 0;
            char last = '@';

            auto convert = [](int number){
                string ans = "";
                do{
                    ans.push_back( '0'+number%10 );
                    number /= 10;
                }while(number);
                reverse(ans.begin(), ans.end());
                return ans;
            };

            for(char c : cur){
                if(c!=last){
                    if(count){
                        string quantity = convert(count);
                        ans = ans + quantity + last;
                    }
                    last = c;
                    count = 1;
                }else{
                    count++;
                }
            }

            string quantity = convert(count);
            ans = ans + quantity + last;

            return ans;
        }
    }
};
