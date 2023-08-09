from typing import List


def intersection(left: List[int], right: List[int]) -> List[int]:
    result = []
    for i in range(0, len(left)):
        for j in range(0, len(right)):
            if left[i] == right[j]:
                result.append(left[i])
                break

    return result


def intersection2(left: List[int], right: List[int]) -> List[int]:
    result = []
    for left_val in left:
        for right_val in right:
            if left_val == right_val:
                result.append(left_val)
                break

    return result


# silly to make intoa function but here we are
def intersection3(left: List[int], right: List[int]) -> List[int]:
    return [i for i in left if i in right]


def main():
    res = intersection([1, 2, 3, 4, 5], [5, 6, 7, 8, 9, 4])
    res2 = intersection2([1, 2, 3, 4, 5], [5, 6, 7, 8, 9, 4, 5, 5, 5, 1, 2, 3, 4])
    res3 = intersection3([1, 2, 3, 4, 5], [5, 6, 7, 8, 9, 4, 5, 5, 5, 1, 2, 3, 4])

    # and the list comprehension
    print(res)
    print(res2)
    print(res3)


if __name__ == "__main__":
    main()
