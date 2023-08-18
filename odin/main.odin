package main

import "core:fmt"

linear_search :: proc(arr: []int, len: int, needle: int) -> bool {
    for index, val in arr {
        if val == needle {
            return true
        }
    }
    return false
}

partition :: proc(arr: ^[]int, lo: int, hi: int) -> int {
    pivot_value := arr[hi]
    current_index := lo - 1

    for i := lo; i < hi; i +=1 {
        if arr[i] <= pivot_value {
            current_index += 1
            tmp := arr[i]
            arr[i] = arr[current_index]
            arr[current_index] = tmp
        }
    }

    current_index += 1
    arr[hi] = arr[current_index]
    arr[current_index] = pivot_value

    return(current_index)
}

quick_sort :: proc(arr: ^[]int, lo: int, hi: int) {
    if lo < hi {
        current_pivot := partition(arr, lo, hi);
        quick_sort(arr, lo, current_pivot - 1);
        quick_sort(arr, current_pivot + 1, hi);
    }
}

main :: proc() {
    fmt.println("hello there here is a for loop")

    values: []int = {1, 2, 3, 4, 5}
    res: bool = linear_search(values, 5, 2)
    fmt.println(res)

    fmt.println("quicksort ----------------")
    arr: []int = {0, 2, 5, 1, 6}
    fmt.println(arr);
    quick_sort(&arr, 0, 4);
    fmt.println(arr);
}
