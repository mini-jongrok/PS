for j in range(int(input())):
    n = int(input())
    m = [input().split() for _ in range(n)]
    l = [[0] * 3 for _ in range(n)]
    for i in range(3):
        m = list(zip(*m[::-1]))
        for index,value in enumerate(m):
            l[index][i] = "".join(m[index])
    print(f"#{j+1}")
    for i in l:
        print(*i)
