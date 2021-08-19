# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def sum(self, root: TreeNode) -> int:
        if root == None:
            return 0
        return root.val + self.sum(root.left) + self.sum(root.right) 
    
    def findAns(self, root: TreeNode, total: int) -> (int,int):
        if root == None:
            return (0,0)
        
        left = self.findAns(root.left, total)
        right = self.findAns(root.right, total)
        s = left[0]+right[0]+root.val
        return (s, max(left[1], right[1], s*(total-s) ) )
    
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        return self.findAns(root, self.sum(root))[1]%1000000007;
