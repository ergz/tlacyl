type QNode<T> = {
    value: T,
    next?: QNode<T>
}

class Queue<T> {
    public length: number;
    private head?: QNode<T>;
    private tail?: QNode<T>;

    constructor() {
        this.head = this.tail = undefined;
        this.length = 0;
    }

    enqueue(item: T): void {
        const node = { value: item } as QNode<T>;
        this.length++;
        if (!this.tail) {
            this.tail = this.head = node
            return
        }

        this.tail.next = node;
        this.tail = node;

    }

    deque(): T | undefined {
        if (!this.head) {
            return undefined;
        }
        this.length--;
        const head = this.head;
        this.head = this.head.next;

        return head.value;
    }

    peek(): T | undefined {
        return this.head?.value
    }
}

test("test that queue works", () => {
    const q = new Queue<number>;

    q.enqueue(12);
    console.log(q);
    expect(q.length).toEqual(1);

    q.enqueue(13);
    console.log(q);
    expect(q.length).toEqual(2);
})