def merge(l, r):
    merged = []
    i, j, inv = 0,0,0
    
    while i < len(l) and j < len(r):
        if l[i] <= r[j]:
            merged.append(l[i])
            i += 1
        else:
            merged.append(r[j])
            j += 1
            inv += len(l) - i  # Count inversions
    
    # Append any remaining elements from left and right halves
    merged += l[i:]
    merged += r[j:]
    return merged, inv

def sort(arr):
    if len(arr) <= 1:
        return arr, 0
    
    mid = len(arr) // 2
    left, li = sort(arr[:mid])
    right, ri = sort(arr[mid:])
    merged, inv = merge(left, right)
    
    tot = li + ri + inv
    return merged, tot

arr = []
n=int(input("Enter size of array:"))
print("Enter array: ")
for i in range(n):
    a=int(input())
    arr.append(a)

sorted, cnt = sort(arr)
print("Sorted array:", sorted)
print("Number of inversions:", cnt)