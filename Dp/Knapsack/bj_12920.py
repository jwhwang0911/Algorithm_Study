def maxcf(n,m,v,c):
    dp = [[0 for col in range(m+1)] for row in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,m+1):
            if j >= v[i-1]:
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-v[i-1]]+c[i-1])
            else:
                dp[i][j] = dp[i-1][j]

    return dp[n][m]


def main():
    n,m = map(int, input().split(' '))  # n 민호 물건 종류 개수, m 가방 무게
    on = n
    v = []  # 물건의 무게
    c = []  # 물건당 민호의 만족도
    for i in range(n):
        p,q,r = map(int, input().split(' '))
        idx = 1
        while r >= idx:
            v.append(p*idx)
            c.append(q*idx)
            idx *= 2
            n += 1
    print(v)
    print(c)

    n -= on

    print(maxcf(n,m,v,c))


if __name__ == "__main__":
    main()