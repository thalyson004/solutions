/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        
        while(left < right){
            int mid = (1LL+left+right)/2LL;
            
            int ans = guess(mid);
            
            
            if(ans == -1) right = mid-1;
            else if(ans == 1) left = mid+1;
            else left = right = mid;
        }
        
        return left;
    }
};
