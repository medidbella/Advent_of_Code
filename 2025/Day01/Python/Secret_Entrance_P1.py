from math import ceil, floor
import sys

position = 50
result = 0

for line in sys.stdin:
	line = line.strip()
	if not line:
		continue

	sign = 1
	if line[0] == 'L':
		sign = -1

	steps = int(line[1:]) * sign
	position += steps

	if position < 0:
		position += ceil(position / 100) * 100

	position %= 100

	if position == 0:
		result += 1

print(result)
