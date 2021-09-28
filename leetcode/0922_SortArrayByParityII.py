class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        odds = []
        even = []
        ans = []
        
        for el in nums:
            if el%2==0:
                odds.append(el)
            else:
                even.append(el)
        
        for i in range(len(odds)):
            ans.append(odds[i])
            ans.append(even[i])
            
            
        return ans
        
