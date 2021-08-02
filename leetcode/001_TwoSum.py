class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        partSum = {}
        for i in range(len(nums)):
            value = nums[i]
            cur = target-value
            
            if partSum.get(cur, None)!=None:
                return [partSum[cur], i]
            
            partSum[value] = i
        
        return [0,0]
        
