N = 8

class Solution:
    def changeBits(self, N):
        bin = format(N, 'b')
        N2 = sum([2**i for i in range(len(bin))])
        return [N2-N,N2]

X = Solution()

print(X.changeBits(N))