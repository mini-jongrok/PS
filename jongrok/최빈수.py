T = int(input())
for _ in range(T):
    i = int(input())
    d = {k: 0 for k in range(101)}
    for j in input().split():
        d[int(j)] += 1
    d = sorted([(k,v) for k,v in d.items()], key = lambda x:(x[1],x[0]), reverse=True)
    print(f"#{i} {d[0][0]}")
