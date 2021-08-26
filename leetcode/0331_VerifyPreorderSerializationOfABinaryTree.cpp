class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        values = preorder.split(',')
        values.reverse()
               
        def dfs(values: list[str]) -> bool:

            try:
                value = values[-1]
                values.pop()
            except:
                return False
            
            if(value == '#'):
                return True
            
            return dfs(values) and dfs(values)
        
        return dfs(values) and len(values)==0
