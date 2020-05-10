_INPUT = """\
4
1
2
3
4
"""


def solver(num):
    return num


def main(*, int=int, input=input):
    from sys import stdin

    input = stdin.readline

    n = int(input())
    for _ in range(n):
        m = int(input())
        print(solver(m))


if __name__ == "__main__":
    import io, sys

    sys.stdin = io.StringIO(_INPUT)
    main()
