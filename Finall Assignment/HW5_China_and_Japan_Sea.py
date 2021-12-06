direction = [[-1,0],[1,0],[0,-1],[0,1]]


def Resultfunc(height):
    global direction
    direction = [[-1,0],[1,0],[0,-1],[0,1]]

    m = len(height)
    n = len(height[0])
    west = 0    # 왼쪽 + 위        0
    east = 1    # 오른쪽 + 아래     1
    result = []
    flow = [[[False,False] for _ in range(n)] for j in range(m)]

    # up-down first

    for i in range(n):
        flowcheck(height,flow,west,m,n,0,i)
        flowcheck(height,flow,east,m,n,m-1,i)

    # left-right first

    for j in range(m):
        flowcheck(height,flow,west,m,n,j,0)
        flowcheck(height,flow,east,m,n,j,n-1)

    for i in range(m):
        for j in range(n):
            if flow[i][j][east] and flow[i][j][west]:
                result.append([i,j])

    return result


def flowcheck(height,flow,whichsea,m,n,row,col):
    flow[row][col][whichsea] = True
    for dir in direction:
        nr,nc = row+dir[0],col+dir[1]
        if nr < 0 or nr >= m or nc < 0 or nc >= n or flow[nr][nc][whichsea]:
            continue
        if height[row][col] < height[nr][nc]:
            flowcheck(height,flow,whichsea,m,n,nr,nc)


if __name__ == "__main__":
    height = []
    m = int(input())
    for _ in range(m):
        height.append(list(map(int,input().split(','))))

    print(Resultfunc(height))