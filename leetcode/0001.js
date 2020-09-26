/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

var twoSum = function(nums, target) {
    var myDict = {};
    
    for(var i = 0; i < nums.length; i++){
        if( myDict.hasOwnProperty(target-nums[i]) ){
            return[ myDict[ target-nums[i] ], i ];
        }
        myDict[ nums[i] ] = i;
    }
};
