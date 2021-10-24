def maxcp(n,m,v,c):
    dp = [[int(0) for row in range(m + 1)] for col in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if v[i - 1] <= j:
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + c[i - 1])
            else:
                dp[i][j] = dp[i - 1][j]

    return dp[n][m]

n,m = map(int, input().split(' '))  # n 민호 물건 종류 개수, m 가방 무게
v = []  # 물건의 무게
c = []  # 물건당 민호의 만족도
for i in range(n):
    p,q,r = map(int, input().split(' '))
    v.append(p)
    c.append(q)
    while r > 1:
        v.append(p*r)
        c.append(q*r)

        r = r//2
        n += 1
print(int(maxcp(n,m,v,c)))
