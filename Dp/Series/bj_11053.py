def main():
    n = int(input())
    li = list(map(int, input().split(" ")))

    ''' 
    일반적인 dp
    O(n) = n^2
    '''
    dp = [1 for i in range(n)]
    for i in range(n):
        for j in range(i):
            if li[i] > li[j]:
                dp[i] = max(dp[i],dp[j]+1)
    print(max(dp))


if __name__ == "__main__":
    main()
