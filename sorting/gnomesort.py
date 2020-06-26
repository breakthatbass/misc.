
def swap(x, y):
    tmp = x;
    x = y;
    y = tmp;

def gnome_sort(arr):
    pos = 0;
    while pos < len(arr):
        if pos == 0 or arr[pos] >= arr[pos - 1]:
            pos += 1
        else:
            swap(arr[pos], arr[pos - 1]);
            pos -= 1;
    return arr


arr = [1003, 4, 902, 12, 45, 1345, 33, 56354, 43, 221, 0, 12, 98, 87]

print("Original array:")
print(arr)

new_arr = gnome_sort(arr) # sort it!

print("Sorted array:")
print(new_arr)