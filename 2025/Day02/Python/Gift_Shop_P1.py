import sys

def twice(s: str) -> int:
    h = s[:len(s)//2]
    return int(h + h)

data = sys.stdin.read().strip()
if data:
    total = 0
    for part in data.split(','):
        a, b = map(int, part.split('-'))
        for n in range(a, b + 1):
            s = str(n)
            if len(s) % 2 == 0 and n == twice(s):
                total += n
    print(total)

