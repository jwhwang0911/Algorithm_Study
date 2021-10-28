'''
    A와 B배열이 모두 1-N까지 한번씩만 사용하여 나타내진 배열
    if A가 1,2,3 ... N이면 B는 최장 증가 수열을 구하는 것과 동일한 과정을 통해 LCS를 구할 수 있음
    ex) A = [1,3,4,2,5] 이면 각각의 index에 1,2,3,4,5의 값을 부여
        B = [5,2,1,3,4] 이면 이제 이 값은 5,4,1,2,3이 들어있다고 생각
        그러면 위의 가정에 맞는 문제로 변환 가능
'''


def main():
    n = int(input())
    Aidx = [0 for _ in range(n)]
    Bidx = [0 for _ in range(n)]
    A = list(map(int,input().split()))
    for i in range(n):
        Aidx[A[i]-1] = i
    B = list(map(int,input().split()))
    for j in range(n):
        Bidx[j] = Aidx[B[j]-1]

    dp = [Bidx[0]]

    for i in range(1, n):
        if dp[len(dp) - 1] < Bidx[i]:
            dp.append(Bidx[i])
        else:
            target = Bidx[i]
            left = 0
            right = len(dp) - 1
            while left < right:
                mid = (left + right) // 2
                if dp[mid] < target:
                    left = mid + 1
                else:
                    right = mid
            dp[left] = Bidx[i]
    print(len(dp))


if __name__ == "__main__":
    main()