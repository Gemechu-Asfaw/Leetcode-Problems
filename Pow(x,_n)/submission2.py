class Solution(object):
    def myPow(self, x, n):
        
        ans = 1
        power = n
        if n<0:
            n = -n
        
        while n:
            if n%2==0:
                n = n//2
                x = x*x
            else:
                ans *= x
                n = n-1
        
        if power < 0:
            ans = 1/ans
        return ans