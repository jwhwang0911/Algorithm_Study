def function(n):
    series = []
    pushpop = []
    p = 1
    for _ in range(n):
        c = int(input())
        if c >= p:
            while c >= p:
                series.append(p)
                p += 1
                pushpop.append('+')
            series.pop()
            pushpop.append('-')
        elif c < p:
            while

        print(pushpop)
        print(series)
    print(pushpop)
    return



if __name__=="__main__":
    n = int(input())
    function(n)