class Solution {
public:
    string decodeAtIndex(string S, int K) {

        long long total = 0;
        for(char letter:S){
            if( isdigit(letter) ){
                total *= letter-'0';
            }else{
                total++;
            }
        }


        reverse(S.begin(), S.end());
        string ans = "";
        for(char letter:S){
            long long prev = total;

            if( isdigit(letter) ){
                total /= letter-'0';

                if(total <= K and K <= prev ){
                    K = ((K-1)%(total)) +1 ;
                }

            }else{
                if(total==K) ans.push_back(letter);
                total--;

            }


        }

        return ans;

    }
};
