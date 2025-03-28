import sys

T = int(sys.stdin.readline())
jinju_cost = 0
freq = [0] * 1001
over_1000 = 0

for _ in range(T):
    line = sys.stdin.readline()
    dest, cost_str = line.split()
    cost = int(cost_str)
    if dest == "jinju":
        jinju_cost = cost
    if cost > 1000:
        over_1000 += 1
    else:
        freq[cost] += 1

if jinju_cost == 1000:
    cnt = over_1000
else:
    cnt = sum(freq[jinju_cost+1:]) + over_1000

sys.stdout.write(str(jinju_cost) + "\n" + str(cnt))
