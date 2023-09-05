import { tree } from "./tree"

type BinaryNode<T> = {
    value: T;
    left: BinaryNode<T> | null;
    right: BinaryNode<T> | null;
};


function bfs(head: BinaryNode<number> | null, needle: number): boolean {
    const q: (BinaryNode<number> | null)[] = [head];

    while (q.length) {
        const current = q.shift() as BinaryNode<number>;

        if (current.value === needle) {
            return true;
        }

        if (current.left) {
            q.push(current.left);
        }

        if (current.right) {
            q.push(current.right);
        }
    }

    return false;
}


test("bfs search works a number of values", function () {
    expect(bfs(tree, 20)).toEqual(true);
    expect(bfs(tree, -20)).toEqual(false);
    expect(bfs(tree, 10)).toEqual(true);
    expect(bfs(tree, 7)).toEqual(true);
})