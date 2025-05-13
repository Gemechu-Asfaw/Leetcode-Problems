class Solution(object):
    mod = int(1e9 + 7)

    def power(self, x, n):
        print(x, n)
        if n==0:
            return 1
        elif n%2==0:
            return self.power((x*x) % self.mod, n//2)
        else:
            return (x * self.power((x*x) % self.mod, n//2)) % self.mod


    def countGoodNumbers(self, n):
        if n%2:
            return (self.power(20, n//2) * 5) % self.mod
        return self.power(20, n//2)