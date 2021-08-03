from itertools import combinations

class Solution:
        
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = []
        
        for l in range(len(nums)+1):
            ans = ans + [sorted(c) for c in combinations(nums, l)] 
        
        ans.sort()
        r = []
        for i, v in enumerate(ans):
            if len(r)==0 or r[-1]!=v:
                r.append(v)
            
        return r
