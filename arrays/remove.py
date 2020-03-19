import array

arr = array.array('i',[1,2,3,4,5])

print('the original array is: ', end='')
for i in range(0, len(arr)):
    print(arr[i], end=' ')

print('\r')

# using remove() to remove 1st occurrence of 1
arr.remove(3)

# printing array after removing
print ('The array after removing is: ',end='')
for i in range (0,len(arr)):
    print (arr[i],end=' ')

print('\r')
