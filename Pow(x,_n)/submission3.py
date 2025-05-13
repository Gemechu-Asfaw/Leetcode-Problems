class Solution(object):
    def myPow(self, x, n):
        print(x, n)
        if n==0:
            return 1
        elif n==1:
            return x
        elif n==-1:
            return 1/x
        elif n%2==0:
                return self.myPow(x*x, n/2)
        else:
            if n>0:
                return x * self.myPow(x*x, n/2)
            else:
                return 1/x * self.myPow(x*x, math.ceil(n/2.0))