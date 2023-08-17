package main

import "core:fmt"

linear_search :: proc(arr: []int, len: int, needle: int) -> bool {
    for index, val in arr {
        if val == needle {
            return true;
        }
    }
    return false;
}

main :: proc() {
    fmt.println("hello there here is a for loop");

    values: []int = {1, 2, 3, 4, 5};
    res: bool = linear_search(values, 5, 2);
    fmt.println(res);
}
