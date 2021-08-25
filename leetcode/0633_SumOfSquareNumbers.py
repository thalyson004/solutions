class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        squares = {}
        sqrt = int(math.pow(c, 0.5)+1);
        
        for i in range( sqrt+1 ):
            p = i*i
            squares[p] = True;
            if squares.get(c-p, False):
                return True
        
        return False
