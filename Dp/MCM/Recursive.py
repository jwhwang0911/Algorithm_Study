import sys


def matrixChain(arr,i,j):
    # Matrix를 하나만 쓰는 경우
    if i == j:
        return 0
    else:
        # i부터 k 까지의 matrix 까지 한묶음, k+1부터 j번째 matrix 까지 한묶음
        _min = sys.maxsize
        for k in range(i,j):
            count = matrixChain(arr,i,k) + matrixChain(arr,k+1,j) + arr[i-1]*arr[k]*arr[j]
            _min = min(_min, count)
        return _min


def dpmcm(li):
    n = len(li)
    dp = [[0 for i in range(n)] for j in range(n)]
    for L in range(2,n):
        for i in range(1,n-L+1):
            j = L+i-1
            dp[i][j] = sys.maxsize
            for k in range(i,j):
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+li[i-1]*li[k]*li[j])
    return dp[1][n-1]
    

def main():
    arr = list(map(int,input().split()))
    print(matrixChain(arr,1,len(arr)-1))
    print(dpmcm(arr))


if __name__ == "__main__":
    main()