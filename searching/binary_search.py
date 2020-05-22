'''
  "Binary search first compares the input value 'x' to the middle element
  of the array. if 'x' is less than the middle value, searching focuses
  on the lower half of the array, otherwise it focuses on the upper half.

  In either case, the next step is to compare 'x' to the middle element of
  the selected half. This process of dividing the range in two continues
  until the value is found or the range is empty."

  Explanation above from page 57 of 'The C Programming Language' by
  Brian Kernighan and Dennis Ritchie.
'''

def binsearch(x, arr):
    low = 0
    mid = 0
    high = len(arr)-1

    while low <= high:
        # break array in half
        mid = int((low + high)/2)

        if x < arr[mid]:
            high = mid-1
        elif x > arr[mid]:
            low = mid+1
        else:
            return mid
    return "no match"


arr1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
arr2 = [10, 34, 42, 56, 79, 91, 98, 105, 106, 1045]

print("arr1:")
print(f"location of 4: {binsearch(4, arr1)}")
print(f"location of 10: {binsearch(10, arr1)}")
print(f"location of 11: {binsearch(11, arr1)}")
print(f"location of 194736: {binsearch(194736, arr1)}")
print()
print("arr2:")
print(f"location of 79: {binsearch(79, arr2)}")
print(f"location of 34: {binsearch(34, arr2)}")
print(f"location of 4: {binsearch(4, arr2)}")
print(f"location of 194736: {binsearch(194736, arr2)}")
