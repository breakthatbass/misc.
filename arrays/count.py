import array

arr = array.array('i',[1, 2, 5, 3, 5, 1, 2, 5])

print(arr.count(5))

# manual version
check = 5
count = 0

for i in arr:
    if check == i:
        count += 1

print(count)
