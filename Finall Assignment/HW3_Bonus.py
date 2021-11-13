'''

    일한시간 = evaluation, 자본주의임 = 옆사람이 일한것보다 많이 일했으면 돈을 천원이라도 더 받아야함
    근데 최소 받아야하는 돈은 1000원임

'''


def budget(li,n):
    arr = [0 for i in range(n)]
    minev = n
    arr[0] = n
    for i in range(1,n):
        if li[i-1] >= li[i]:
            arr[i] = arr[i-1]-1
        else:
            arr[i] = arr[i-1]+1
        minev = min(minev,arr[i])
    minev -= 1
    sum = 0
    for i in range(n):
        sum += 1000*(arr[i]-minev)
        arr[i] -= minev
        arr[i] *= 1000

    return sum, arr


if __name__ == "__main__":
    li = list(map(int,input("evaluation = ").split(",")))
    n = len(li)
    print(budget(li,n))
