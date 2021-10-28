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


def main():
    arr = list(map(int,input().split()))
    print(matrixChain(arr,1,len(arr)-1))


if __name__ == "__main__":
    main()