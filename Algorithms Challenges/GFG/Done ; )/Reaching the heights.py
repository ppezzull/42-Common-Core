arr = [2,3,4,5]
n = len(arr)

def reaching_height (n, arr):
    if arr.count(arr[0]) == n and n != 1:
        return [-1]
    else:
        arr.sort()
        out = []
        for i in range(n):
            if i % 2 == 0:
                out.append(arr.pop())
            else:
                out.append(arr.pop(0))
        return out
        
print(reaching_height (n, arr))