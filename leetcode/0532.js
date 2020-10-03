/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findPairs = function(nums, k) {
    let copied = [...nums];
    copied.sort( function(a,b){return a-b;}  );
    let l = 0;
    let ans = 0;
    for(let r=1;r < copied.length; r++){
        while( r+1 < copied.length && copied[r]==copied[r+1] ) r++;
        while( l+1 < r && copied[r]-copied[l] > k ) l++;
        if( copied[r]-copied[l]==k ) ans++;
    }
    return ans;
};
