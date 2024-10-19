##
# Fibonacci memoized
#

fib_cache = {}

# Compute the nth term of the Fibonacci sequence; we take the sequence to begin with 1 rather than zero here.
def fib(n):
    if n not in fib_cache:
        if n == 1:
            return 1
        elif n == 2:
            return 1
        else:
            fib_cache[n] = fib(n-1) + fib(n-2)
            return fib_cache[n]
    else:
        return fib_cache[n]

for i in range(1, 100):
    print(fib(i))
