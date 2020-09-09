class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        versionA = list(map(int, version1.split('.')))
        versionB = list(map(int, version2.split('.')))
        
        for a,b in itertools.zip_longest(versionA,versionB, fillvalue=0):
            if a < b:
                return -1
            if a > b:
                return 1
            
        return 0
