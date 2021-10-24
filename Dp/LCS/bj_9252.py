def main():
    s1 = input()
    s2 = input()
    s3 = []
    dp = [[0 for col in range(len(s1)+1)] for row in range(len(s2)+1)]
    for i in range(1,len(s2)+1):
        for j in range(1,len(s1)+1):
            if s2[i-1] == s1[j-1]:
                dp[i][j] = dp[i-1][j-1]+1
            else:
                dp[i][j] = max(dp[i-1][j],dp[i][j-1])

    a = len(s2)
    b = len(s1)
    print(dp[a][b])
    while dp[a][b] != 0:
        if dp[a][b] == dp[a-1][b]:
            a -= 1
        elif dp[a][b] == dp[a][b-1]:
            b -= 1
        else:
            s3.insert(0,s1[b-1])
            a -= 1
            b -= 1
    print("".join(s3))


if __name__ == "__main__":
    main()