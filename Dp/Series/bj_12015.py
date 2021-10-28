def main():
    n = int(input())
    if n != 0:
        li = list(map(int, input().split(" ")))

        dp = [li[0]]

        for i in range(1,n):
            if dp[len(dp)-1] < li[i]:
                dp.append(li[i])
            else:
                target = li[i]
                left = 0
                right = len(dp)-1
                while left < right:
                    mid = (left + right) // 2
                    if dp[mid] < target:
                        left = mid + 1
                    else:
                        right = mid
                dp[left] = target
        print(len(dp))
    else:
        print(0)


if __name__ == "__main__":
    main()

