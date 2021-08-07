class Solution:
    def minCut(self, s: str) -> int:
        isPal = {}
        for i in range(len(s)):
            isPal[ (i,i) ] = True
        
        def check(i: tuple[int,int]) -> bool:
            if i[0]+1==i[1]:
                return s[i[0]]==s[i[1]]
            
            return s[i[0]]==s[i[1]] and isPal.get((i[0]+1, i[1]-1), False)
        
        for l in range(2, len(s)+1):
            for start in range( len(s)+1-l ):
                end = start+l-1;
                isPal[(start, end)] = check( (start, end) )

                
        dist = [9999999999]*(len(s)+1)
        dist[len(s)] = 0
        for i in reversed(range(0,len(s))):
            for j in range(i, len(s)):
                if isPal[(i,j)]:
                    dist[i] = min(dist[i], dist[j+1] + 1)
                    
        return dist[0]-1
