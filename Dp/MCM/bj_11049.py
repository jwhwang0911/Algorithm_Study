import sys
def main():
    n = int(input())
    r = []
    c = []
    for i in range(n):
        a,b = map(int,input().split(" "))
        r.append(a)
        c.append(b)

    # i번째 매트리스 사용해서 j번째까지 사용
    dp = [[0 for i in range(n+1)] for j in range(n+1)]

    # 사용할 Matrix의 개수
    for L in range(2,n+1):
        for i in range(1,n-L+1):
            j = i + L - 1
            for k in range(i,j):
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+r[i-1]*c[k-1]*c[j-1])
    print(dp[1][n])


if __name__=="__main__":
    main()