class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if len(points)==0:
            return 0
        
        points.sort()
        ans = 1
        last = points[0][1]
        
        for i in range(1, len(points) ):
            start, end = points[i]
            
            if start>last:
                ans = ans+1
                last = end
            elif last > end:
                last = end
        
        return ans
