class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        secret = list(secret)
        guess = list(guess)
        count  = {}
        A = 0
        B = 0
        for c in secret:
            try:
                count[c]+=1
            except KeyError:
                count[c] = 1
        
        for i in range(0, len(guess)):
            c1 = secret[i]
            c2 = guess[i]
            
            if c1 == c2:
                A+=1
                count[c1]-=1
                guess[i]='x'
       
        
        for i in range(0, len(guess)):
            c = guess[i]
            try:
                if count[c]>0:
                    B+=1
                    count[c]-=1
            except KeyError:
                count[c]=0
                
        return str(A)+"A"+str(B)+"B"
            
        
