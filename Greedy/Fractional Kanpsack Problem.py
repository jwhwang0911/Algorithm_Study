'''

    처음 pperw에 [profit/weight, index] 저장해서 앞에 값을 기준으로 정렬
    그러면 오름차순 정렬 -> 가장 마지막 값부터 접근해서
    남은 무게 < weight이면
        weight - 그녀석의 무게
        result 그 인덱스 = 1
        maxprofit += 그녀석의 전체 profit

    아니면
        사용되는 무게 = weight
        result 그 인덱스 = 그녀석무게 / weight
        maxprofit += 사용되는 무게 * pperw

'''


if __name__ == "__main__":
    n,m = map(int,input().split(","))
    p = list(map(int,input().split(" ")))
    w = list(map(int,input().split(" ")))
    pperw = []
    maxprofit = float(0)
    result = [0 for _ in range(n)]
    for i in range(len(p)):
        pperw.append([p[i]/w[i],i])

    pperw.sort()

    for i in range(n):
        if w[pperw[n-1-i][1]] < m:
            result[pperw[n-1-i][1]] = 1
            m = m-w[pperw[n-1-i][1]]
            maxprofit = maxprofit + p[pperw[n-1-i][1]]
        else:
            result[pperw[n-1-i][1]] = m/w[pperw[n-1-i][1]]
            maxprofit = maxprofit + m*pperw[n-1-i][0]
            break

    print(maxprofit)
    print(result)


