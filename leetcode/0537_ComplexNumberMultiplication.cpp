class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        real1 = int(num1.split('+')[0])
        img1 = int(num1.split('+')[1][:-1])
        real2 = int(num2.split('+')[0])
        img2 = int(num2.split('+')[1][:-1])
        
        
        real = real1*real2 - img1*img2
        img = real1*img2 + real2*img1
        
        ans = f"{real}+{img}i"
        
        return ans
        
        
