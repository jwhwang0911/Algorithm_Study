def main():
    n = int(input())
    li = list(map(int,input().split(" ")))
    dp1 = [1 for col in range(n)]
    dp2 = [1 for col in range(n)]
    for i in range(n):
        for j in range(i):
            if li[i] > li[j]:
                dp1[i] = max(dp1[j]+1,dp1[i])
            if li[n-i-1] > li[n-j-1]:
                dp2[n-i-1] = max(dp2[n-j-1]+1,dp2[n-i-1])
    dp = []
    for i in range(n):
        dp.append(dp1[i]+dp2[i]-1)
    print(max(dp))


if __name__ == "__main__":
    main()