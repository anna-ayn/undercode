MOD = 10**9 + 7
S = input()
N = int(input())

cnts = [0] * 26
inversions = 0
for c in S:
    idx = ord(c) - ord("a")
    inversions += sum(cnts[idx + 1 :])
    cnts[idx] += 1

print("inversions of S ", inversions)
inversions *= N
g = 0
for c_1 in range(26):
    for c_2 in range(c_1 + 1, 26):
        g += cnts[c_1] * cnts[c_2]

inversions += g * N * (N - 1) // 2
print(inversions % MOD)
