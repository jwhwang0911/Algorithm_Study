def lcsrec(a,b,n,m):
    if n == 0 or m == 0:
        return 0
    else:
        if a[n-1] == b[m-1]:
            return 1+lcsrec(a,b,n-1,m-1)
        else:
            return max(lcsrec(a,b,n,m-1), lcsrec(a,b,n-1,m))


def main():
    s1 = input()
    s2 = input()
    print(lcsrec(s1,s2,len(s1),len(s2)))


if __name__=="__main__":
    main()