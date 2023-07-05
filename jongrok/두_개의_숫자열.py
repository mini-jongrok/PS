for k in range(int(input())):
    n,m = map(int,input().split())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    long = a if len(a) >= len(b) else b
    short = a if len(a) < len(b) else b
    ans = 0
    for i in range(len(long) - len(short) + 1):
        t = 0
        for j in range(len(short)):
            t += (long[i+j] * short[j])
        ans = max(t,ans)
    print(f"#{k + 1} {ans}")
