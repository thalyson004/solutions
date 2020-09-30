/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    let myArray = new Array( nums.length );
    
    for(let i = 0; i < nums.length; i++){
        if( nums[i]>=1 && nums[i]<=nums.length ){
            myArray[ nums[i]-1 ] = 1;
        } 
    }
    
    let ans = 0;
    while( ans<nums.length && myArray[ans]==1 ) ans++;
    
    return ans+1;
};
