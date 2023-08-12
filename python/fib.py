def fib(n, counter):
    if n == 0 or n == 1:
        return n

    else:
        counter.append(1)
        print("calling fib")
        return fib(n - 1, counter) + fib(n - 2, counter)


def fib_memo(n, memo={}, counter=[]):
    if n == 0 or n == 1:
        return n

    if not memo.get(n):
        counter.append(1)
        memo[n] = fib_memo(n - 1, memo, counter) + fib_memo(n - 2, memo, counter)

    return memo[n]


count = []
fib(6, counter=count)
sum(count)

fib_counter = []
fib_memo(6, memo={}, counter=fib_counter)
sum(fib_counter)
