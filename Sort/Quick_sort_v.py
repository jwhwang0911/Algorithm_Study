import random


def partition(x,l,h):
    pivot = x[l]
    i = l
    j = h
    while i < j:
        while x[i] <= pivot and i < h:
            i += 1
        while x[j] > pivot and j > l:
            j -= 1
        if i < j:
            x[i], x[j] = x[j], x[i]
    x[l], x[j] = x[j], x[l]
    return j


def quick(x,low,h):
    if low >= h:
        return
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