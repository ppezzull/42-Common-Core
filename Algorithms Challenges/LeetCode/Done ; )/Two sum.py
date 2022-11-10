nums = [6,0,12,3,9]
target = 12


class Solution(object):
    def twoSum(self, nums, target):
        iter = len(nums)
        for i in range(iter):
            for j in range(i+1,iter):
                if nums[i] + nums[j] == target:
                    return [i,j]

X = Solution()
print(X.twoSum(nums, target))