"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        ans = []
        
        def dfs(root, level=0)->None:
            if root==None:
                return None
            if level == len(ans):
                ans.append([])
            ans[level].append( root.val )
            
            for child in root.children:
                dfs(child, level=level+1)
                
        dfs(root, level=0)
        return ans
