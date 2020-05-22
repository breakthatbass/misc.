from termcolor import colored

def insertion_sort(array):
    # loop through the 2nd element in array to the last one
    for i in range(1, len(array)):
        key_item = array[i]

        j = i - 1

        while j >= 0 and array[j] > key_item:
            array[j+1] = array[j]
            j -= 1

        array[j + 1] = key_item

    return array

arr = [1003, 4, 902, 12, 45, 1345, 33, 56354, 43, 221, 0, 12, 98, 87]

print(colored("Original array:", 'red', attrs=['bold']))
print(arr)

insertion_sort(arr) # sort it!

print(colored("Sorted array:", 'green', attrs=['bold']))
print(arr)
