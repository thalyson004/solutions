class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        def solve(left: int, right: int, dp: dict[tuple[int],int])->int:
            if left>right:
                return 0
            
            if dp.get((left, right),None)!= None:
                return dp.get((left, right))
            
            l = right-left+1
            func, sig = (max, 1) if l%2==0 else (min, -1)
            
            dp[(left,right)] = func(solve(left+1, right, dp)+sig*piles[left], 
                                    solve(left, right-1, dp)+sig*piles[right])
                                    
            return dp[(left,right)]
                  
        left = 0
        right = len(piles)-1
        dp = { }
        sum = solve(left, right, dp)
        
        return True if sum>0 else False
