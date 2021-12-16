adj_mat = [[0, 0, 1, 1, 0, 0],
           [0, 0, 0, 1, 1, 0],
           [0, 0, 0, 1, 0, 1],
           [0, 0, 0, 0, 0, 1],
           [0, 0, 0, 0, 0, 1],
           [0, 0, 0, 0, 0, 0]]


def topological_sort(adj_mat):
    in_degrees = []
    stack = []
    answer = []

    for i in range(len(adj_mat)):
        temp = 0
        for col in range(len(adj_mat)):
            temp += adj_mat[col][i]
        in_degrees.append(temp)

    print("in_degrees: ", in_degrees)

    for i in range(len(in_degrees)):
        if in_degrees[i] == 0:
            stack.append(i)

    print("stack: ", stack)

    while stack:
        node = stack.pop()
        answer.append(node)
        print("pop된 노드: ", node)

        for i in range(len(adj_mat[node])):
            if adj_mat[node][i] != 0:
                in_degrees[i] -= 1
                if in_degrees[i] == 0:
                    print("진입차수 0이 된 노드: ", i)
                    stack.append(i)

    print("answer: ", answer)


print(topological_sort(adj_mat))