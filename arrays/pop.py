import array

arr = array.array('i',[])

for i in range(1, 11):
    arr.append(i)

print('the original array is: ', end='')
for i in range(0, len(arr)):
    print(arr[i], end=' ')

print('\r')

# POP
# removes element at the position mentioned and returns it
print('popped element is: ', end='')
print(arr.pop(2))

print('the array after popping is: ', end='')
for i in range(0, len(arr)):
    print(arr[i], end=' ')

print('\r')
