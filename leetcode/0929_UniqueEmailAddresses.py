class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        ans:set = set()
        
        for email in emails:
            first, second = email.split("@")
            
            first = first.replace(".", "")
            if first.find("+") != -1:
                first = first[0:first.find("+")]
            
            ans.add( first+"@"+second )
            
        return len(ans)
        
