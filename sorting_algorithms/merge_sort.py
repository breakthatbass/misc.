def merge_sort(array):
    if len(array) < 2: return

    # split array down the middle into two arrays named left and right
    midpoint = len(array)//2

    left = array[:midpoint]
    right = array[midpoint:]

    merge_sort(left)
    merge_sort(right)

    i = 0
    while len(left) > 0 and len(right) > 0:
        if left[0] < right[0]:
            array[i] = left.pop(0)
        else:
            array[i] = right.pop(0)
        i += 1

    rest = left + right
    while len(rest) > 0:
        array[i] = rest.pop(0)
        i += 1


arr = [1003, 4, 902, 12, 45, 1345, 33, 56354, 43, 221, 0, 12, 98, 87]

print(f"Original array:\n{arr}")
merge_sort(arr) # sort it!
print(f"Sroted array:\n{arr}")
