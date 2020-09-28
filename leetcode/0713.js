/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numSubarrayProductLessThanK = function(nums, k) {
    if(nums.length===0 || k <= 1)
        return 0;
    
    var count = 0;
    var start = 0;
    var prod = 1;
    
    for(var end = 0; end < nums.length; end++){
        prod *= nums[end];
        
        while(prod>=k){
            prod /= nums[start];
            start++;
        }
        
        count += (end-start+1);
    }
    
    return count;
};
