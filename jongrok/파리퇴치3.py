from typing import List
def plus(x:int,y:int,m:List[List[int]], M:int) -> int:
    ans = m[x][y]
    dx,dy = [0,1,0,-1], [1,0,-1,0]
    for i in range(1,M):
        for j in range(4):
            if 0<= x + dx[j] * i < len(m) and 0<= y + dy[j] * i < len(m):
                ans += m[x + dx[j] * i][y + dy[j] * i]
    return ans

def x_spray(x:int,y:int,m:List[List[int]], M:int) -> int:
    ans = m[x][y]
    dx,dy = [-1,1,1,-1], [1,1,-1,-1]
    for i in range(1,M):
        for j in range(4):
            if 0<= x + dx[j] * i < len(m) and 0<= y + dy[j] * i < len(m):
                ans += m[x + dx[j] * i][y + dy[j] * i]
    return ans


for k in range(int(input())):
    N,M = map(int,input().split())
    matrix = [list(map(int,input().split())) for _ in range(N)]
    ans = 0
    for i in range(N):
        for j in range(N):
            ans = max(plus(i,j,matrix,M), x_spray(i,j,matrix,M), ans)
    print(f"#{k + 1} {ans}")






