# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
        def dfs(root: TreeNode, remainSum: int, cur: List[int], ans: List[List[int]]) -> None:
            
            if root==None:
                return None
            
            if root.left==None and root.right==None:
                if remainSum==root.val:
                    cur.append(root.val)
                    ans.append(cur[:])
                    cur.pop()
                return None
                    
            if root.left!=None:
                cur.append(root.val)
                dfs(root.left, remainSum-root.val, cur, ans)
                cur.pop()
                
            if root.right!=None:
                cur.append(root.val)
                dfs(root.right, remainSum-root.val, cur, ans)
                cur.pop()
        
        ans = []
        cur = []
        dfs(root, targetSum, cur, ans)
        return ans
    
    
