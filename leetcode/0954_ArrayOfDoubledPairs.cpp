class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        def add(item:int, dictonary: dict[int, int]) -> None:
            if dictonary.get(item,None) == None:
                dictonary[item] = 1
            else:
                dictonary[item] = dictonary[item] + 1
                
        positive = {}
        negative = {}
        
        for item in arr:
            if item >= 0:
                add(item, positive)
            else:
                add(item, negative)
        
        for value in sorted(positive.keys()):
            while positive[value]>0:
                positive[value] = positive[value]-1
            
                if positive.get(value*2, 0) == 0:
                    return False
        
                positive[value*2] = positive[value*2]-1
            
        for value in sorted(negative.keys(), reverse=True):
            while negative[value]>0:
                negative[value] = negative[value]-1
            
                if negative.get(value*2, 0) == 0:
                    return False
        
                negative[value*2] = negative[value*2]-1
        
        
        return True
        
