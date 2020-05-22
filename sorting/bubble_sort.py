from termcolor import colored


def bubble_sort(array):
    n = len(array)

    for i in range(n):
        for j in range(n-i-1):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]

arr = [1003, 4, 902, 12, 45, 1345, 33, 56354, 43, 221, 0, 12, 98, 87]

print(colored("Original array:", 'red', attrs=['bold']))
print(arr)

bubble_sort(arr) # sort it!

print(colored("Sorted array:", 'green', attrs=['bold']))
print(arr)
