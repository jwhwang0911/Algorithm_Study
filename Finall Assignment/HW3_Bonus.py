def budget(li):
    n = len(li)
    arr = [1 for i in range(n)]
    for i in range(1,n):
        if li[i-1] < li[i]:
            arr[i] = max(arr[i-1]+1,arr[i])

    for i in range(1,n):
        if li[n-i] < li[n-1-i]:
            arr[n-1-i] = max(arr[n-i]+1,arr[n-1-i])

    sum = 0
    for i in range(n):
        sum += 1000*arr[i]

    return sum
