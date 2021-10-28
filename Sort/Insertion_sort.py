import random


def insertion(x):
    n = len(x)
    for i in range(n):
        key = x[i]
        j = i-1
        while j >= 0 and key < x[j]:
            x[j+1] = x[j]
            j -= 1
        x[j+1] = key


def random_List(size):
    result = []

    for v in range(size):
        result.append(random.randint(0,20))

    return result


def main():
    li = random_List(10)
    print(li)
    insertion(li)
    print(li)


if __name__=="__main__":
    main()