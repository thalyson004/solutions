class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> count;
        int ans = 0;
        int lagest = 0;

        function<int(int)> sumDigits = [&sumDigits](int value){
            return value?value%10+sumDigits(value/10):0;
        };

        for(int i =1; i <=n; i++){
            int sm = sumDigits(i);
            count[sm]++;
            if(count[sm]==lagest) ans++;
            else if(count[sm]>lagest){
                lagest = count[sm];
                ans = 1;
            }
        }

        return ans;
    }
};
