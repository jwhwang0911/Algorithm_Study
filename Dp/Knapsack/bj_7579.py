import sys


def main():
    # m byte를 확보해야함
    n, m = map(int, input().split(" "))
    # 현재 활성화된 앱이 사용중인 메모리의 바이트 수
    mem = list(map(int, input().split()))
    # 각 앱을 비활성화 했을 경우의 비용
    c = list(map(int, input().split()))

    cost = 0
    for _ in range(n):
        cost += c[_]

    # 비용 j를 사용해서 얻을 수 있는 최대 memory -> N 행의 리스트 중 m이상의 메모리를 확보할 수 있는 최소 비용을 구하면 됨 == 최소 비용을 통해 m 만큼의 메모리 확보
    # dp[i][j] = i 번째까지의 앱을 사용했을 때 j의 비용을 통해 얻을 수 있는 최대 메모리
    dp = [[0 for row in range(cost + 1)] for col in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, cost + 1):
            if j >= c[i - 1]:
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i - 1]] + mem[i - 1])
            else:
                dp[i][j] = dp[i - 1][j]

    for i in range(cost + 1):
        if dp[n][i] >= m:
            print(i)
            break


if __name__ == "__main__":
    main()
