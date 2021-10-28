import random


def partition(x,l,h):
    i = l - 1
    pivot = x[h]
    for j in range(l,h):
        if pivot >= x[j]:
            i += 1
            x[i], x[j] = x[j], x[i]
    x[i+1], x[h] = x[h], x[i+1]
    return i+1


def quick(x,low,h):
    if low < h:
        j = partition(x,low,h)
        quick(x,low,j-1)
        quick(x,j+1,h)


def random_List(size):
    result = []

    for v in range(size):
        result.append(random.randint(0,20))

    return result


def main():
    li = random_List(10)
    print(li)
    quick(li,0,len(li)-1)
    print(li)


if __name__=="__main__":
    main()