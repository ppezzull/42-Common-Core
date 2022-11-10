arr1 = [1, 3, 5, 7]
arr2 = [0, 2, 6, 8, 9]
n = 4
m = 5

class Solution:
    def merge(self, arr1, arr2, n, m): 
        arr3 = sorted(arr1 + arr2)
        arr1[:] = arr3[:n]
        arr2[:] = arr3[n:]
        
X = Solution()

X.merge(arr1, arr2, n, m)

for i in arr1:
    print(i,end=" ")
for i in arr2:
    print(i,end=" ")
