"""
CSC 249
M3LAB2 - Merge Sort (py)
norrisa
2/21/23
source: zybooks 3.11
Notes:
We expect big theta (n lg n) swaps
(measuring compares might get tricky with this, they all 
happen within merge)
temp space on the order of (n) is needed for copying sub-arrays
"""

DEBUG = True 

def merge(numbers, low, mid, high):
    merged_size = high - low + 1               # Size of merged partition
    merged_numbers = [0] * merged_size    # Dynamically allocates temporary array
                                          # for merged numbers
    merge_pos = 0                         # Position to insert merged number
    left_pos = low                         # Initialize left partition position
    right_pos = mid + 1                     # Initialize right partition position
   
    if DEBUG:
        print("Merging [", low, "",mid,"] and [", mid+1, "-", high, "]")
    # Add smallest element from left or right partition to merged numbers
    while left_pos <= mid and right_pos <= high:
        if numbers[left_pos] <= numbers[right_pos]:
            merged_numbers[merge_pos] = numbers[left_pos]
            left_pos += 1
        else:
            merged_numbers[merge_pos] = numbers[right_pos]
            right_pos += 1
        merge_pos = merge_pos + 1
   
    # If left partition is not empty, add remaining elements to merged numbers
    while left_pos <= mid:
        merged_numbers[merge_pos] = numbers[left_pos]
        left_pos += 1
        merge_pos += 1
   
    # If right partition is not empty, add remaining elements to merged numbers
    while right_pos <= high:
        merged_numbers[merge_pos] = numbers[right_pos]
        right_pos = right_pos + 1
        merge_pos = merge_pos + 1
   
    # Copy merge number back to numbers
    for merge_pos in range(merged_size):
        numbers[low + merge_pos] = merged_numbers[merge_pos]


def merge_sort(numbers, low, high):
    mid = 0

    if low < high:
        mid = (low + high) // 2  # Find the midpoint in the partition

        # Recursively sort left and right partitions
        merge_sort(numbers, low, mid)
        merge_sort(numbers, mid + 1, high)
            
        # Merge left and right partition in sorted order
        merge(numbers, low, mid, high)


# Create a list of unsorted values
numbers = [61, 76, 19, 4, 94, 32, 27, 83, 58]

# Print unsorted list
print('UNSORTED:', numbers)

# Initial call to merge_sort
merge_sort(numbers, 0, len(numbers) - 1)

# Print sorted list
print('SORTED:', numbers)