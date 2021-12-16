def topologicalsort(use,trunk):
    degrees = []
    tps = []
    result = []

    for i in range(len(trunk)):
        temp = 0
        for col in range(len(trunk)):
            temp += trunk[col][i]
            if trunk[col][i] == 1 and trunk[i][col] == 1:
                return ""
        degrees.append(temp)

    for i in range(len(degrees)):
        if degrees[i] == 0:
            tps.append(i)

    while tps:
        node = tps.pop()
        result.append(node)

        for i in range(len(trunk[node])):
            if trunk[node][i] != 0:
                degrees[i] -= 1
                if degrees[i] == 0:
                    tps.append(i)

    answer = []
    for char in result:
        answer.append(use[char])
    afterword = "".join(answer)

    return afterword

def LanguageOrder(words):
    used = set()
    for st in words:
        for c in st:
            temp = set(c)
            used = used | temp
    use = list(used)
    if len(use) == 0:
        return ""
    trunk = [[0 for col in range(len(use))] for row in range(len(use))]
    check = 0
    for i in range(len(words)):
        for j in range(i + 1, len(words)):
            for k in range(len(words[i])):
                if k >= len(words[j]):
                    return ""
                cf = words[i][k]
                cn = words[j][k]
                if cf == cn:
                    continue
                u = use.index(cf)
                v = use.index(cn)
                if trunk[u][v] == 0:
                    trunk[u][v] = 1
                break


    return topologicalsort(use,trunk)
