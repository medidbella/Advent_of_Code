import sys

def repeated(s):
    return s in (s + s)[1:-1]

data = sys.stdin.read().strip()
if not data:
    exit()

ranges = (r.split('-') for r in data.split(','))
total = 0

for a, b in ranges:
    for n in range(int(a), int(b) + 1):
        if repeated(str(n)):
            total += n

print(total)

