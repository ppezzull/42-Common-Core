nums1 = [1,2]
nums2 = [3,4]

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        nums3 = nums1 + nums2
        nums3.sort()
        m = len(nums3)
        if m % 2 == 0:
            median_1 = nums3[(m//2)-1]
            median_2 = nums3[m//2]
            return(median_1 + median_2) / 2
        return nums3[m//2]


X = Solution()
print(X.findMedianSortedArrays(nums1,nums2))