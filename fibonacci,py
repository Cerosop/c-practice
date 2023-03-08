arr = {0: 0, 1: 1}
def fibonacci(n):
    if n == 0:
        return 0
    if not arr.get(n):
        arr[n] = fibonacci(n - 1) + fibonacci(n - 2)
    return arr[n]

def fi_acc(n):
    if n == 0:
        return 0
    return fibonacci(n) + fi_acc(n - 1)

n = int(input())
print(fi_acc(n))
