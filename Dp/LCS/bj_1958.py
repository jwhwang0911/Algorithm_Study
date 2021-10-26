def main():
    s1 = input()
    s2 = input()
    s3 = input()
    l1 = len(s1)
    l2 = len(s2)
    l3 = len(s3)

    dp = [[[0 for i in range(l1+1)] for j in range(l2+1)] for k in range(l3+1)]
    for i in range(1,l3+1):
        for j in range(1,l2+1):
            for k in range(1,l1+1):
                if s3[i-1] == s2[j-1] and s2[j-1] == s1[k-1]:
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1
                else:
                    dp[i][j][k] = max(dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1])
    print(dp[l3][l2][l1])


if __name__ == "__main__":
    main()