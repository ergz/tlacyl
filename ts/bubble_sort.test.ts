function bubble_sort(arr: number[]): void {
    for (let i = 0; i < arr.length; i++) {
        for (let j = 0; j < arr.length - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                const t = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = t;
                
            }
        }
    }
}

test("bubble sort works", () => {
    const a = [2, 1, 3, 4, 5];
    bubble_sort(a);
    expect(a).toEqual([1, 2, 3, 4, 5]);
})