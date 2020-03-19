import array

arr = array.array('i',[1, 2, 3, 1, 2, 5])

# using typecode to print datatype of array
# returns datatype by which array is initialized
print ('The datatype of array is: ', end='')
print (arr.typecode)

# using itemsize to print itemsize of array
# returns size in bytes of single array element
print ('The itemsize of array is: ', end='')
print (arr.itemsize)

# using buffer_info() to print buffer info. of array
# returns tuple with addres which array is stored
# and number of elements in it
print ('The buffer info. of array is: ', end='')
print (arr.buffer_info())
