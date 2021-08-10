class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        n = len(s)
        left = [0]*(n+1)
        right = [0]*(n+1)
        for i in range(n):
            if i>0:
                left[i] = left[i-1]
            if s[i] == "1":
                left[i] = left[i]+1
        
        for i in reversed(range(n)):
            if i<n-1:
                right[i] = right[i+1]
            if s[i] == "0":
                right[i] = right[i]+1
        
        ans = min(right[0], left[-2])
        for i in range(n):
            ans = min(ans, left[i]+right[i+1])
            
        return ans
