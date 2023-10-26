def quick_sort(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[0]
    left = []
    right = []

    for element in arr[1:]:
        if element < pivot:
            left.append(element)
        else:
            right.append(element)

    return quick_sort(left) + [pivot] + quick_sort(right)

# Input from the user
user_input = input("Enter a list of numbers separated by spaces: ")
user_input = user_input.strip()
user_input = user_input.split()
arr = [int(num) for num in user_input]

sorted_arr = quick_sort(arr)
print("Sorted list:", sorted_arr)
