# correct out = [0, 1, 3, 4, 5, 0, 2, 1, 1, 0]


nums = [1456,4274,4931,6553,9719,3426,4956,4559,9392,4423]
class Solution:
    def longestPalindrome(self, s):
        palindromes = []
        i = 0
        while len(s) != i:
            s2 = s[i:]
            while s2 != s2[::-1]:
                s2 = s2[:-1]
            if len(s2) > 1:
                palindromes.append(s2)
            i += 1
        if len(palindromes) == 0:
            return s[0]
        return max(palindromes, key = len)



X = Solution()
print(X.countSmaller(nums))
