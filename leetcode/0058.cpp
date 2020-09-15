class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if len(s.split()) != 0:
            return len(s.split()[-1])
        else:
            return 0
