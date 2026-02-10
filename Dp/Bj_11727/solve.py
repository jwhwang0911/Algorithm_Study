N = int(input())


# for N in range(1, 12):
#     results = [1, 3]
        
#     for i in range(2, N):
#         results.append(results[i-1] + 2 * results[i-2])

#     print(results[N-1] % 10007)

if N == 1:
    print(1)
elif N == 2:
    print(3)
else:
    result = 2*2**N - 1 if N % 2 == 1 else 2*2**N + 1
    result = int(result//3) % 10007

    print(result)