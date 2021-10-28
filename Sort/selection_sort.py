import random


def selection(x):
    n = len(x)
    for i in range(n-1):
        _min = i
        for j in range(i+1,n):
            if x[_min] > x[j]:
                _min = j
        x[_min], x[i] = x[i], x[_min]


def random_List(size):
    result = []

    for v in range(size):
        result.append(random.randint(0,20))

    return result


def main():
    li = random_List(10)
    print(li)
    selection(li)
    print(li)


if __name__=="__main__":
    main()