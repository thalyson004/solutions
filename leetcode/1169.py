class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        ans = []
        
        for i in range(len(transactions)):
            name = transactions[i].split(',')[0]
            time = int(transactions[i].split(',')[1])
            ammount = int(transactions[i].split(',')[2])
            city = transactions[i].split(',')[3]
            
            if ammount>1000:
                ans.append(transactions[i])
            else:
                invalid = False 
                for j in range(0, len(transactions)):
                    invalid = (name==transactions[j].split(',')[0] and city!=transactions[j].split(',')[3] and abs(int(transactions[j].split(',')[1])-time)<=60 )
                    
                    if invalid==True:
                        break
                if invalid:
                    ans.append( transactions[i] )
        
        return ans
        
