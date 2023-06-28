function binary_search(haystack: number[], needle: number): boolean {
	let lo = 0;
	let hi = haystack.length;

	while (lo < hi) {
		const m = Math.floor(lo + (hi - lo) / 2);
		const v = haystack[m];

		if (v === needle) {
			return true;
		} else if (v > needle) {
		 	hi = m;
		} else {
			lo = m + 1;
		}
	}
	return false;
}

test("test binary search", () => {
	expect(binary_search([1, 2, 3, 4, 5, 6], 5)).toBe(true);

})

test("test binary search can return false", () => {
	expect(binary_search([1, 2, 3, 4, 5, 6], 50)).toBe(false);

})
