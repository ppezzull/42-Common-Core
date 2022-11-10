A = [10, 2, 50, 12, 48, 13]
K1 = 2
K2 = 6
N = len(A)

class Solution:
    def sumBetweenTwoKth(self, A, N, K1, K2):
        A = sorted(A)
        return sum(A[K1:K2-1])

X = Solution()
print(X.sumBetweenTwoKth(A, N, K1, K2))

