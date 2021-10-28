import random
import sys


def merge(x):
    if len(x) > 1:
        mid = len(x)//2
        L = x[:mid]
        R = x[mid:]
        merge(L)
        merge(R)
        L.append(sys.maxsize)
        R.append(sys.maxsize)
        i = j = 0
        for k in range(len(x)):
            if L[i] < R[j]:
                x[k] = L[i]
                i += 1
            else:
                x[k] = R[j]
                j += 1


def random_List(size):
    result = []

    for v in range(size):
        result.append(random.randint(0,20))

    return result


def main():
    li = random_List(10)
    print(li)
    merge(li)
    print(li)


if __name__=="__main__":
    main()