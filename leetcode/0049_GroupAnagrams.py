class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = {}
        
        for name in strs:
            inorder = str(sorted(name))
            if ans.get(inorder, None) != None:
                ans[inorder].append(name)
            else:
                ans[inorder] = [name]
        
        return list(ans.values())
