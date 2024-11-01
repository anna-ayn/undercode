def main():
    n, m = map(int, input().split())

    in_java = [0] * n
    in_cpp = [0] * n

    for _ in range(m):
        p = int(input())
        L = int(input())
        if L == 1:
            in_cpp[p - 1] = 1
        if L == 2:
            in_java[p - 1] = 1

    for i in range(n):
        if in_cpp[i] and in_java[i]:
            print(i + 1)


if __name__ == "__main__":
    main()
