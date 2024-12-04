data = [[int(n) for n in line.split()] for line in open("input.txt").read().splitlines()]

def gaps(line): return [a-b for a,b in zip(line, line[1:])]
def safe_increase(line): return all(0<g<4  for g in gaps(line))
def safe_decrease(line): return all(0>g>-4 for g in gaps(line))
def is_safe(line): return safe_increase(line) or safe_decrease(line)
print("Part 1:", sum(is_safe(line) for line in data))

def trimmed(line): return [line[:i]+line[i+1:] for i in range(len(line))]
print("Part 2:", sum(any(is_safe(c) for c in [line, *trimmed(line)]) for line in data))