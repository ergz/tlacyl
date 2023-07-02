function qs(arr: number[], lo: number, hi: number): void {
    if (lo >= hi) {
        return
    }

    const pivot_index = partition(arr, lo, hi);
    qs(arr, lo, pivot_index - 1);
    qs(arr, pivot_index + 1, hi);
}

function partition(arr: number[], lo: number, hi: number): number {
    const pivot = arr[hi];
    let idx = lo - 1;

    for (let i = lo; i < hi; i++) {
        if (arr[i] <= pivot) {
            idx++;

            // if the value of arr[i] is less than or equal to the pivot point value
            // then switch places with it (placete it in the ith position), at the end of this iteration we will 
            // hve a weakly sorted array where everything less than the pivot point
            // will be on the left side of the pivot
            const tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;
        }
    }

    // we need to move the pivot value to the where the last point where 
    // it was larger than value of, so that everything to the left it, is
    // in fact less then it. 
    idx++;
    arr[hi] = arr[idx];
    arr[idx] = pivot;

    return (idx);
}

function quick_sort(arr: number[]): void {
    qs(arr, 0, arr.length - 1);
}


test("quick sort works", () => {
    let arr = [2, 3, 1, 6, 5, 10, 8, 9];
    quick_sort(arr);
    expect(arr).toEqual([1, 2, 3, 5, 6, 8, 9, 10]);
})

test("quick sort works in worst case possible", () => {
    let brr = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1];
    quick_sort(brr);
    expect(brr).toEqual([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);

})

