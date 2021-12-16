def merge(l1, l2):
    re = []
    l = h = 0
    while l < len(l1) and h < len(l2):
        if l1[l] < l2[h]:
            re.append(l1[l])
            l += 1
        else:
            re.append(l2[h])
            h += 1
    re += l1[l:]
    re += l2[h:]
    return re


def sorted_list(lists):
    k = len(lists)
    if k == 0:
        return []

    while len(lists) != 1:
        li = []
        while len(lists) >= 2:
            li.append(merge(lists[0], lists[1]))
            lists.pop(0)
            lists.pop(0)
        if len(lists) == 1:
            li.append(lists[0])
            lists.pop()
        lists = li
    return lists[0]
