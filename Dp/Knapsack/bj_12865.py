def maxprofit(n,k,w,v):
    dp = [[0 for row in range(k+1)] for col in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,k+1):
            if w[i-1] <= j:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]]+v[i-1])
            else:
                dp[i][j] = dp[i-1][j]

    use = [0 for i in range(n)]
    i = int(n)
    j = int(k)
    while j != 0:
        if dp[i][j] != dp[i-1][j]:
            use[i-1] = 1
            j = j - w[i-1]
        i = i-1
    print(use)

    return dp[n][k]


def main():
    n,k = map(int, input().split(' '))
    w = []
    v = []
    for i in range(n):
        a,b = map(int, input().split(' '))
        w.append(a)
        v.append(b)
    print(w)
    print(v)
    print(maxprofit(n,k,w,v))


if __name__ == "__main__":
    main()