import array

arr = array.array('i',[])

for i in range(1, 11):
    arr.append(i)

print('the original array is: ', end='')
for i in range(0, len(arr)):
    print(arr[i], end=' ')

print('\r')

# INSERT
# insert to insert a value at a specific position

arr.insert(4, 50) #inserts 5 at the 2nd position

print('the array after insertion is: ', end='')
for i in range(0, len(arr)):
    print(arr[i], end=' ')

print('\r')
