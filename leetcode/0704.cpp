/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    let l = 0, r = nums.length - 1;
    while(l<r){
        let m = Math.floor((l+r)/2);
        if(nums[m]<target) l = m+1;
        else r = m;
    }
    
    if(l==nums.length || nums[l]!=target) return -1;
    else return l;
};
