from typing import List


def bubble_sort(arr: List[int]):
    total_iterations = 0
    for i in range(len(arr)):
        total_iterations += 1
        for j in range(len(arr) - 1):
            if arr[j] > arr[j + 1]:
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
    print(f"the total number of iterations: {total_iterations}")


def bubble_sort2(arr: List[int]):
    total_swaps = 1
    total_iterations = 0
    for i in range(len(arr)):
        if total_swaps == 0:
            break
        total_swaps = 0
        total_iterations += 1
        for j in range(len(arr) - 1):
            if arr[j] > arr[j + 1]:
                total_swaps += 1
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    print(f"total iterations: {total_iterations}")


if __name__ == "__main__":
    a = [2, 1, 3, 4, 5]
    print(a)
    bubble_sort2(a)
    print(a)
