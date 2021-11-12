if __name__ == "__main__":
    cost = list(map(int,input().split(" ")))
    n = len(cost)
    i = profit = 0
    buy = sel = i
    while i < n-1:
        if cost[i] > cost[i+1]:
            i += 1
            buy = i
        else:
            sel = i+1
            if sel < n-1:
                while cost[sel] < cost[sel+1]:
                    sel += 1
                    if sel >= n-1:
                        break
            profit = profit + cost[sel]-cost[buy]
            buy = i = sel + 1
    print(profit)