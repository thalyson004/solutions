class Solution:
    def fib(self, n: int) -> int:
        fib = [0,1]
        while len(fib)<=n:
            fib.append( fib[-1]+fib[-2] ) 
            
        return fib[n]
