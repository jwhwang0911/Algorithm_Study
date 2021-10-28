def rec(n,m,w,p):
    if n == 0 or m == 0:
        return 0
    if w[n-1] <= m:
        return max(rec(n-1,m,w,p), rec(n-1,m-w[n-1],w,p)+p[n-1])
    else:
        return rec(n-1,m,w,p)


def main():
    n,m = map(int, input().split(' '))
    p = []
    w = []
    for i in range(n):
        a,b = map(int, input().split(' '))
        p.append(a)
        w.append(b)
    print(p)
    print(w)
    print(rec(n,m,w,p))


if __name__ == "__main__":
    main()