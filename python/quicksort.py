def partition(arr, lo, hi):
    pivot_value = arr[hi]
    current_index = lo - 1

    for i in range(lo, hi):
        if arr[i] <= pivot_value:
            current_index += 1
            arr[current_index], arr[i] = arr[i], arr[current_index]
    current_index += 1
    arr[hi] = arr[current_index]
    arr[current_index] = pivot_value
    return current_index

def quicksort(arr, lo, hi):
    if lo < hi:
        part = partition(arr, lo, hi)
        partition(arr, lo, part - 1)
        partition(arr, part + 1, hi)


