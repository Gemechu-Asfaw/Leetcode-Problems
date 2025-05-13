class Solution:
    def longestConsecutive(self, arr: List[int]) -> int:
        
        n = len(arr)
        if n==0 or n==1:
            return n
        
        arr.sort()
        i = 1
        ans = 1
        sum = 1
        
        while i<n:
            if arr[i]-arr[i-1]==1:
                sum += 1
                ans = max(ans,sum)
            elif arr[i]-arr[i-1]>0:
                sum = 1
            i += 1
        
        return ans