# quicksort(arr):
#      If length of arr <= 1:
#          Return arr
#      Else:
#          Set pivot to the middle element of arr
#          Initialize left sub-array to elements less than pivot
#          Initialize right sub-array to elements greater than pivot
#          Return quicksort(left) + [pivot] + quicksort(right)


import random
def quick(arr):
  if len(arr)>1:
    pivot=arr[0]
    l=[x for x in arr if x<pivot]
    r=[x for x in arr if x>pivot]
    return quick(l) +[pivot]+quick(r)
  else:
    return arr
  
arr=[random.randint(0,100) for _ in range(12)]
print(quick(arr))