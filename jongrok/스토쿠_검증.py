#version1
for t in range(int(input())):
    m = [list(map(int,input().split())) for _ in range(9)]
    b,r,c = sum([len(set(m[i][j] for i in range(r,r+3) for j in range(c,c+3))) == 9 for r in range(0,9,3) for c in range(0,9,3)]), sum([len(set(m[i])) == 9 for i in range(9)]), sum([len(set([m[i][j] for i in range(9)])) == 9 for j in range(9)])
    print(f"#{t+1} {1 if b == r == c == 9 else 0}")


#version2
from typing import List
def box(m:List[int],row:int,left:int) -> bool:
    return len(set([m[i][j] for i in range(row, row+3) for j in range(left,left +3)])) == 9
def row(m:List[int],row:int) -> bool:
    return len(set([m[row][i] for i in range(9)])) == 9
def col(m:List[int], col:int) -> bool:
    return len(set([m[i][col] for i in range(9)])) == 9
for t in range(int(input())):
    m = [list(map(int,input().split())) for _ in range(9)]
    b = sum([box(m,i,j) for i in range(0,9,3) for j in range(0,9,3)])
    r = sum([row(m,i) for i in range(9)])
    c = sum([col(m,i) for i in range(9)])
    print(f"#{t+1} {1 if b == r == c == 9 else 0}")
