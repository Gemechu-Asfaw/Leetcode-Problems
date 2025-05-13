class Solution:
    def countOdds(self, low: int, high: int) -> int:
        
        low = int(math.floor(low/2) * 2)
        high = int(math.ceil(high/2) * 2)
        return (high-low)//2