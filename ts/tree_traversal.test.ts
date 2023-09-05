import { tree } from "./tree"

type BinaryNode<T> = {
    value: T;
    left: BinaryNode<T> | null;
    right: BinaryNode<T> | null;
};

// pre order 
function walk(current: BinaryNode<number> | null, path: number[]): number[] {
    if (!current) {
        return path;
    }

    path.push(current.value);
    walk(current.left, path);
    walk(current.right, path);

    return path;

}

function pre_order_search(head: BinaryNode<number>): number[] {
    const path: number[] = [];
    walk(head, path);

    return path;

}

test("Pre order", function () {
    expect(pre_order_search(tree)).toEqual([
        20,
        10,
        5,
        7,
        15,
        50,
        30,
        29,
        45,
        100,
    ]);
});