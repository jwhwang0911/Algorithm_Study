def check(li):
    for x in li:
        print(stackcheck(x))


def stackcheck(x):
    ch = []
    for y in x:
        if y == '(':
            ch.append(y)
        elif y == ')':
            if len(ch) == 0:
                return "NO"
            ch.pop()
    if len(ch) == 0:
        return "YES"
    else:
        return "NO"


if __name__=="__main__":
    n = int(input())
    li = []

    for _ in range(n):
        li.append(list(input()))

    check(li)
